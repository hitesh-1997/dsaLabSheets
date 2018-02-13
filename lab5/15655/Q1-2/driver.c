#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "def.h"
#include "merge.h"
#include "mem.h"
Record readfile(FILE *fp,Record arr,int *sz);


int main(int argv,char **argc){
	Record arr;
	int *sz = (int*)myalloc(sizeof(int));
	*sz = 12;
	arr = (Record)myalloc(sizeof(struct record)*(*sz));
	FILE *fp;
	fp = fopen("10240.txt","r");
	if(!fp){
		printf("cant open file\n");
		exit(1);
	}
	arr = readfile(fp,arr,sz);
	int i;
	/*for(i=0;i<*sz;i++){
		printf("name: %s	cgpa = %lf\n",arr[i].name,arr[i].cgpa);
	}*/
	
	printf("sorting the array %d\n",*sz-1);
    clock_t t;
    t = clock();
    mergesort(arr,0,*sz-1);
    t = clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("time taken :%lf\n",time_taken);
    /*for(i=0;i<*sz;i++){
		printf("name: %s	cgpa = %lf\n",arr[i].name,arr[i].cgpa);
	}*/
	
	
	
/*	char name[500];*/
/*	scanf("%[a-z ]\n",name);*/
/*	printf("%s\n",name);*/
}

Record readfile(FILE *fp,Record arr,int *sz){
	char name[50];
	double cgpa;
	int i=0;
	while(fscanf(fp,"%49[^,],%lf\n",name,&cgpa)!=EOF){
		if(i>=*sz){
			arr = (Record)myrealloc(arr,2*(*sz)*sizeof(struct record));
			(*sz)*=2;
		}
		arr[i].cgpa = cgpa;
		int len = strlen(name);
		arr[i].name = (char*)myalloc((len+1)*sizeof(char));
		strcpy(arr[i].name,name);
		
		i++;
		
	}
	arr = (Record)myrealloc(arr,sizeof(struct record)*i);
	*sz = i;
	return arr;
}
