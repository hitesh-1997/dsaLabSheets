#ifndef MEM_H
#define MEM_H

#include <stddef.h>
#define ull unsigned long long int

extern ull heap;
extern ull maxheap;

void *myalloc(ull size);
void myfree(void *ptr);
void *myrealloc(void *ptr,ull size);
 
/*

using structures

struct memory{
	void *ptr;
	size_t sizeAlloc;
};

typedef struct memory *Mem; 




Mem myalloc(size_t sz);
void myfree(Mem m);
*/

// 2nd method using extra 4bytes for storing the size

#endif
