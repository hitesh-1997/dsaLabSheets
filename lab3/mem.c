#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*

using structures

Mem myalloc(size_t sz){
	Mem m = (Mem)malloc(sizeof(struct memory));
	m->ptr = malloc(sz); 
	m->sizeAlloc = sz;
	totalHeap+=sz;
	return m;
}

void myfree(Mem m){
	totalHeap-=m->sizeAlloc;	
	free(m->ptr);
	free(m);
}
*/



    
ull heap=0;
ull maxheap=0;

void *myalloc(ull size){
	void* temp = malloc(size+sizeof(ull));
    if(!temp)
        return NULL;
	ull *ptr = (ull*)temp;
	*ptr  = size+sizeof(ull);
	++ptr;
	heap+=(size+sizeof(ull));
	if(heap>maxheap)
        maxheap=heap;
	//prullf("total heap:- %d\n",heap);
	return temp+sizeof(ull);
}

void myfree(void *ptr){
	ull *temp = (ull*)ptr;
	--temp;
	heap-=*temp;
	//prullf("total heap:- %d\n",heap);
	//printf("size alocates:- %llu\n",*temp);
	free(ptr-sizeof(ull));
}

void *myrealloc(void *ptr,ull size){
	void *temp = ptr-sizeof(ull);
	ull *t = (ull*)temp;
	ull sizeold = *t;
	heap-=sizeold;
	heap+=(size+sizeof(ull));
	temp = realloc(temp,size+sizeof(ull));
	t = (ull*)temp;
	*t=(size+sizeof(ull));
	//prullf("total heap:- %d\n",heap);
	//prullf("size alocates:- %d\n",*t);
	return ++t;
}
