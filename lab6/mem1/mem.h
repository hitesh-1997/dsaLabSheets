#ifndef XH
#define XH

extern int heap;
extern int maxheap;
extern int myindex;
extern int size;

struct memory{
	void *ptr;
	int size;
};

typedef struct memory *Mem; 

void* myalloc(int sizemem);
void myfree(void* ptr);
void *myrealloc(void *ptr,int size); 

#endif 
