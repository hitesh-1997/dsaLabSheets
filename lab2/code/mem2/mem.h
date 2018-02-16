#ifndef MEM_H
#define MEM_H

extern int heap;
extern int maxheap;

void *myalloc(int size);
void myfree(void *ptr);
void *myrealloc(void *ptr,int size);
 
#endif
