#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int totalHeap=0;

/*

using structures

Mem myalloc(size_t sz){
	Mem m = (Mem)malloc(sizeof(struct memory)+4);
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

void *myalloc(int sz){
	void *temp = malloc(sz+4);
    if(!temp){
        printf("can't allocate more mem\n");
        return NULL;
    }
	int *first = (int*)temp;
	*first = (sz+4);	
	totalHeap+=(sz+4);
    void *ptr = ++first;
    //printf("starting addrresssssssss ********- %u\n",temp);
    //printf("returned addrresssssssss ********- %u\n",ptr);
    return ptr;
	//return temp;
}

void myfree(void *ptr){
	//printf("************************\n");
	int *temp = (int*)ptr;
	//printf("*********************= %llu\n",*temp);
	totalHeap-=*temp;
	free(ptr);
}

