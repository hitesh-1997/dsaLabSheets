#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "def.h"
#include "merge.h"
Record readfile(FILE *fp,Record arr,int *sz);
/*
int totalheap=0;
int maxheap=0;

void *myalloc(int n){
	void *temp = malloc(n+sizeof(int));
	int *first = (int*)temp;
	*first = n;
	totalheap+=n;
	if(maxheap<totalheap)
		maxheap = totalheap;	
	printf("current heap= %llu\n",totalheap);
	printf("max heap = %llu\n",maxheap);
	return ++first;
}

void myfree(void *temp){
	int *sz = (int*)temp;
	--sz;
	totalheap-=*sz;
	free(temp);
	
	printf("current heap= %llu\n",totalheap);
	printf("max heap = %llu\n",maxheap);
}
*/


/*
unsigned int curHeapSize=0;
unsigned int maxHeapSize=0;

void *myalloc(unsigned int size){
	void* ptr = malloc(size+sizeof(unsigned int));
	unsigned int *temp = (unsigned int *)ptr;
	*temp=(size+sizeof(unsigned int));
	curHeapSize+=(size+sizeof(unsigned int));
	
	if(maxHeapSize<curHeapSize)
		maxHeapSize = curHeapSize;
	printf("new allocated curHeap = %llu\n",curHeapSize);
	printf("new allocated maxHeap = %llu\n",maxHeapSize);

	printf("size allocated = %llu\n",*temp);
	return ++temp;
}

void myfree(void *ptr){
	unsigned int *s = (unsigned int *)ptr;
	s--;
	unsigned int size = *s;
	curHeapSize-=size;
	free(s);
	printf("new allocated curHeap = %llu\n",curHeapSize);
	printf("new allocated maxHeap = %llu\n",maxHeapSize);
	printf("size allocated = %llu\n",size);
}
*/

int main(int argv,char **argc){
	Record arr;
	int *sz = (int*)malloc(sizeof(int));
	*sz = 12;
	arr = (Record)malloc(sizeof(struct record)*(*sz));
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
			arr = (Record)realloc(arr,2*(*sz)*sizeof(struct record));
			(*sz)*=2;
		}
		arr[i].cgpa = cgpa;
		int len = strlen(name);
		arr[i].name = (char*)malloc((len+1)*sizeof(char));
		strcpy(arr[i].name,name);
		
		i++;
		
	}
	arr = (Record)realloc(arr,sizeof(struct record)*i);
	*sz = i;
	return arr;
}
