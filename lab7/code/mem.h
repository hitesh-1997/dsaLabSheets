#ifndef MEM_H
#define MEM_H

extern long long int heap;
extern long long int maxheap;


void *myalloc(int size);
void myfree(void *ptr);
void *myrealloc(void *ptr,int size);

#endif
