#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

int heap=0;

void *myalloc(int size){
	void* temp = malloc(size+sizeof(int));
	int *ptr = (int*)temp;
	*ptr  = size;
	++ptr;
	heap+=size;
	
	//printf("total heap:- %d\n",heap);
	return temp+4;
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
	heap+=size;
	temp = realloc(temp,size+sizeof(int));
	t = (int*)temp;
	*t=size;
	//printf("total heap:- %d\n",heap);
	//printf("size alocates:- %d\n",*t);
	return ++t;
}