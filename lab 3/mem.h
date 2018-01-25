#ifndef MEM_H
#define MEM_H

#include <stddef.h>
#define ull unsigned long long int
extern int totalHeap;

struct memory{
	void *ptr;
	size_t sizeAlloc;
};

typedef struct memory *Mem; 

/*
using structures

Mem myalloc(size_t sz);
void myfree(Mem m);
*/

// 2nd method using extra 4bytes for storing the size

void *myalloc(int sz);
void myfree(void *ptr);


#endif
