#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int heap=0;
int maxheap=0;

void *myalloc(int size){
	void* temp = malloc(size+sizeof(int));
    	if(!temp)
        	return NULL;
	int *ptr = (int*)temp;
	*ptr  = size+4;
	++ptr;
	heap+=(size+4);
	if(heap>maxheap)
	        maxheap=heap;
	//printf("total heap:- %d\n",heap);
	return temp+4;  // instead of 4 use sizeof(int)
}

void myfree(void *ptr){
	int *temp = (int*)ptr;
	--temp;
	heap-=*temp;
	//printf("total heap:- %d\n",heap);
	//printf("size alocates:- %d\n",*temp);
	free(ptr-4);
}

void *myrealloc(void *ptr,int size){
	void *temp = ptr-4;
	int *t = (int*)temp;
	int sizeold = *t;
	heap-=sizeold;
	heap+=(size+4);
	temp = realloc(temp,size+sizeof(int));
	if(!temp)
		return NULL;
	if(heap>maxheap)
	    maxheap=heap;
	t = (int*)temp;
	*t=(size+4);
	//printf("total heap:- %d\n",heap);
	//printf("size alocates:- %d\n",*t);
	return ++t;
}

struct rec{
	char cardno[20];
	char bankcode[10];
	char expdate[10];
	char fname[20];
	char lastname[20];
};

typedef struct rec *Record;

struct rec *readFile(FILE *fp,Record arr,int *sz,int *index);
void insertInOrder(Record arr,int n,struct rec x,int* add);
void swap(Record arr,int i,int j);
void insertionSort(Record arr,int n,int* add);

unsigned long long int stack=0;
int totalHeap=0;

int main(int argv,char **argc){
	int *s;
	s = (int*)myalloc(sizeof(int));
	*s=50;
	Record arr = (Record)myalloc((*s)*sizeof(struct rec));
   // printf("%d\n",atoi(argc[1]));
	
	int *index;
	index = (int*)myalloc(sizeof(int));
	*index=0;
	clock_t t1,t;
	t1 = clock();
	FILE *fout = fopen("readtime.txt","w");
	while(*index < 20000){
		FILE *fp = fopen("100.txt","r");
		if(!fp){
			printf("\ncants open file\n");
			exit(1);
		}
		arr = readFile(fp,arr,s,index);
		t = clock()-t1;
		double timetaken = (double)t/CLOCKS_PER_SEC;
		fprintf(fout,"time taken for reading input: %d is = %lf\n",*index,timetaken);
	}
	arr = (Record)myrealloc(arr,(*index)*sizeof(struct rec));
	int sz = *index;
	printf("struct is:size %d\n",sz);
		
	/*for(i=0;i<sz;i++){
		printf("f,l = %s	%s\n",arr[i].cardno,arr[i].lastname);	
	}*/
	
	int sortsz=100;
	int k;
	fout = fopen("insert_time_stack.txt","w");
	for(k=sortsz;k<=sz;k*=2){
		
		Record arrcopy;
		arrcopy=(Record)myalloc(k*sizeof(struct rec));
		int cp;
		for(cp=0;cp<k;cp++)
			arrcopy[cp]=arr[cp];
		int i=0;
		int* add=&i;
		t = clock();
		insertionSort(arrcopy,k-1,add);
		t = clock()-t;
		double timetaken = (double)t/CLOCKS_PER_SEC;
		fprintf(fout,"time taken for n= : %d is = %lf\n and stack used= %llu\n",k,timetaken,stack);
		stack=0;
        myfree(arrcopy);
		printf("progress k-: %d   ",k);
	}
	printf("\n");
	int i;
	/*for(i=0;i<sz-1;i++){
		//printf("f,l = %s	%s\n",arr[i].cardno,arr[i].lastname);
		if(atoll(arr[i+1].cardno)<atoll(arr[i].cardno)){
			printf("not sorted\n");
			break;		
		}	
	}*/

}

struct rec *readFile(FILE *fp,Record arr,int *sz,int *index){
	char line[200];
	char delim[2];
	delim[0]=',';
	delim[1]='\0';
	while(fgets(line,200,fp)!=NULL){
		if(*index>=*sz){
			arr = (Record)myrealloc(arr,2*(*sz)*sizeof(struct rec));
			(*sz)*=2;	
		}
		line[0]=',';
		int size = strlen(line);
		line[size-2]=',';
		//printf("line is: %s\n",line);	
		strcpy(arr[*index].cardno,strtok(line,delim));
		strcpy(arr[*index].bankcode,strtok(NULL,delim));
		strcpy(arr[*index].expdate,strtok(NULL,delim));
		strcpy(arr[*index].fname,strtok(NULL,delim));
		strcpy(arr[*index].lastname,strtok(NULL,delim));
		(*index)++;
	}
	return arr;
}

void swap(Record arr,int i,int j){
	struct rec temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;	
}

void insertionSort(Record arr,int n,int* add){
	if(n==0){
		if(abs(add-&n)>stack)
			stack = (add-&n);
		return;
	}
	insertionSort(arr,n-1,add);
	insertInOrder(arr,n-1,arr[n],add);
}

void insertInOrder(Record arr,int n,struct rec x,int* add){
	// n point up to which array is sorted
	if(n==-1 || atoll(arr[n].cardno)<atoll(x.cardno)){
		if(abs(add-&n)>stack)
			stack = (add-&n);
		arr[n+1]=x;
		return;	
	}
	else{
		arr[n+1]=arr[n];
		insertInOrder(arr,n-1,x,add);	
	}
}








