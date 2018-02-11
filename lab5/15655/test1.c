#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record{
	double cgpa;
	char *name;
};

typedef struct record *Record;

Record *readfile(FILE *fp,Record *arr,int *sz);



int heap=0;

void *myalloc(int size){
	void* temp = malloc(size+sizeof(int));
	int *ptr = (int*)temp;
	*ptr  = size;
	++ptr;
	heap+=size;
	
	printf("total heap:- %d\n",heap);
	return temp+4;
}

void myfree(void *ptr){
	int *temp = (int*)ptr;
	--temp;
	heap-=*temp;
	printf("total heap:- %d\n",heap);
	printf("size alocates:- %d\n",*temp);
	free(ptr-4);
}

void *myrealloc(void *ptr,int size){
	void *temp = ptr-4;
	int *t = (int*)temp;
	int sizeold = *t;
	heap-=sizeold;
	heap+=size;
	temp = realloc(temp,size+sizeof(int));
	t = (int*)temp;
	*t=size;
	printf("total heap:- %d\n",heap);
	printf("size alocates:- %d\n",*t);
	return ++t;
}


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

int main(){
	Record *arr;
	int *sz = (int*)myalloc(sizeof(int));
	*sz = 12;
	arr = (Record*)myalloc(sizeof(Record)*(*sz));
	FILE *fp;
	fp = fopen("1024.txt","r");
	if(!fp){
		printf("cant open file\n");
		exit(1);
	}
	arr = readfile(fp,arr,sz);
	int i;
	for(i=0;i<*sz;i++){
		//printf("name: %s	cgpa = %lf\n",arr[i]->name,arr[i]->cgpa);
	}
	
	printf("frreing all memory:\n");
    printf("freeing all strings:\n");
    for(i=0;i<*sz;i++){
        myfree(arr[i]->name);
    }
    printf("freeing all structs:\n");
    for(i=0;i<*sz;i++){
        myfree(arr[i]);
    }
    printf("freeeing final array:\n");
    myfree(arr);
    printf("freeing size pointer:\n");
    myfree(sz);
    printf("deon all final heap:- %d\n",heap);
    
	
/*	char name[500];*/
/*	scanf("%[a-z ]\n",name);*/
/*	printf("%s\n",name);*/
}

Record *readfile(FILE *fp,Record *arr,int *sz){
	char name[50];
	double cgpa;
	int i=0;
	while(fscanf(fp,"%49[^,],%lf\n",name,&cgpa)!=EOF){
		if(i>=*sz){
			arr = (Record*)myrealloc(arr,2*(*sz)*sizeof(Record));
			(*sz)*=2;
		}
		arr[i] = (Record)myalloc(sizeof(struct record));
		arr[i]->cgpa = cgpa;
		int len = strlen(name);
		arr[i]->name = (char*)myalloc((len+1)*sizeof(char));
		strcpy(arr[i]->name,name);
		
		i++;
		
	}
	arr = (Record*)myrealloc(arr,sizeof(Record)*i);
	*sz = i;
	return arr;
}
