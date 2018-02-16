#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

long long int heap=0;
long long int maxheap=0;

void *myalloc(int size){
	void* temp = malloc(size+sizeof(int));
    	if(!temp)
        	return NULL;
	int *ptr = (int*)temp;
	*ptr  = (size+4);
	++ptr;
	heap+=(size+4);
	if(heap>maxheap)
	    maxheap=heap;
	//printf("total heap:- %d\n",heap);
	return temp+4;  // instead of 4 use sizeof(int)
}

void myfree(void *ptr){
	if(!ptr)
		return;
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