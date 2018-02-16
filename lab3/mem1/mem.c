 #include"mem.h"
#include<stdio.h>
#include<stdlib.h>

int heap=0;
int maxheap=0;
int myindex=0;
int size =0;
struct memory **heapAllocs;

void* myalloc(int sizemem) {
	if(!heapAllocs){
		heapAllocs = (struct memory**)malloc(10*sizeof(struct memory*));
		size=10;
	}
	void* ptr = malloc(sizemem);
	heap+=sizemem;
	if(heap>maxheap) {
		maxheap=heap;
	}
	struct memory *rec = (struct memory*)malloc(sizeof(struct memory));
	rec->ptr = ptr;
	rec->size = sizemem;
	if(myindex>=size){
		heapAllocs = (struct memory**)realloc(heapAllocs,2*size*sizeof(struct memory*));
		size*=2;
	}
	heapAllocs[myindex++]=rec;
	printf("size = %d and total size= %d\n",heap,maxheap);
	return ptr;
}

void myfree(void* ptr) {
	int i;
	for(i=0; i<myindex;i++){
		if(heapAllocs[i]->ptr == ptr)
			break;
	}
	if(i==myindex)
		return;
	heap-=heapAllocs[i]->size;
	for(;i<myindex-1;i++){
		heapAllocs[i] = heapAllocs[i+1];
	}
	size--;	
	myindex--;
	int val = (3*myindex)/2;
	if(val < size){
		heapAllocs = (struct  memory**)realloc(heapAllocs,val*sizeof(struct memory*));
		size=val;
	}
	free(ptr);
	printf("size = %d and total size= %d\n",heap,maxheap);
}

void *myrealloc(void *ptr,int size){
	int i;
	for(i=0; i<myindex;i++){
		if(heapAllocs[i]->ptr == ptr)
			break;
	}
	if(i==myindex){
		return NULL;
	}
	heap-=heapAllocs[i]->size;
	heapAllocs[i]->ptr = realloc(heapAllocs[i]->ptr,size);
	heapAllocs[i]->size = size;
	heap+=size;
	if(heap>maxheap) {
		maxheap=heap;
	}
	printf("size = %d and total size= %d\n",heap,maxheap);
	return heapAllocs[i]->ptr;

}
