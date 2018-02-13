#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record{
	double cgpa;
	char *name;
};

typedef struct record *Record;

void *readfile(FILE *fp,void *arr,int *sz);

int totalheap=0;
int maxheap=0;

void *myalloc(int n){
	void *temp = malloc(n+sizeof(int));
	int *first = (int*)temp;
	*first = n;
	totalheap+=n;
	if(maxheap<totalheap)
		maxheap = totalheap;	
/*	printf("memory heap:-%llu\n",totalheap);*/
/*	printf("total hea= %llu\n",maxheap);*/
	return temp;
}

void myfree(void *temp){
	int *sz = (int*)temp;
	--sz;
	totalheap-=(*sz);
	printf("size= %d\n",*sz);
	//free(temp);
/*	printf("memory heap:-%llu\n",totalheap);*/
/*	printf("total hea= %llu\n",maxheap);*/
	
}

void *retnext(void *ptr){
	int *temp = (int*)ptr;
	temp++;
	return temp;
}

int main(){
	
	printf("size of struct record;- %llu\n",sizeof(struct record));
	printf("size of Record:- %llu\n",sizeof(Record));
//	printf("size of Record:- %llu\n",sizeof(Record));
	//printf("size of Record:- %llu\n",sizeof(Record));
	
	
	
	Record *arr;
	void *szptr = myalloc(sizeof(int));
	int *sz = (int*)retnext(szptr);
	*sz = 1;
	void *arrptr = (void*)myalloc(sizeof(Record)*(*sz));
	arr = (Record*)retnext(arrptr);
	FILE *fp;
	fp = fopen("10.txt","r");
	if(!fp){
		printf("cant open file\n");
		exit(1);
	}
	arrptr = readfile(fp,arrptr,sz);
	arr = (Record*)retnext(arrptr);
	int i;
/*	for(i=0;i<*sz;i++){*/
/*		printf("name: %s	cgpa = %lf\n",arr[i]->name,arr[i]->cgpa);*/
/*	}*/
	
	for(i=0;i<*sz;i++){
		myfree(arr[i]->name);
	}
	
	myfree(arrptr);
	
/*	char name[500];*/
/*	scanf("%[a-z ]\n",name);*/
/*	printf("%s\n",name);*/
}

void *readfile(FILE *fp,void *arrptr,int *sz){
	char name[50];
	double cgpa;
	int i=0;
	Record *arr = (Record*)retnext(arrptr);
	while(fscanf(fp,"%49[^,],%lf\n",name,&cgpa)!=EOF){
		//printf("line is: %s and cgpa = %lf\n",name,cgpa);
		if(i>=*sz){
			arrptr = realloc(arrptr,(2*(*sz)*sizeof(Record)+sizeof(int)));
			int *temp = (int*)arrptr;
			*temp = 2*(*sz);
			arr = (Record*)retnext(arrptr);
			(*sz)*=2;
			totalheap+=*sz;
		}
		arr[i] = (Record)myalloc(sizeof(struct record));
		arr[i]->cgpa = cgpa;
		int len = strlen(name);
		arr[i]->name = (char*)myalloc((len+1)*sizeof(char));
		strcpy(arr[i]->name,name);
		
		i++;
		
	}
	arrptr = realloc(arrptr,(sizeof(Record)*i+sizeof(int)));
	int *temp = (int*)arrptr;
	*temp = i;
	*sz = i;
	return arrptr;
}
