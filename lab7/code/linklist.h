#ifndef List_H
#define List_H

#include "mem.h"
#include "hash.h"

struct record{
	char *name;
	int index;
	int cnt;
};

struct node{
    struct record* data;
    struct node *next;
};

struct ll{
    struct node *head;
    int size;
};

typedef struct node* Node;
typedef struct ll* LL;

LL createList();
Table insertAtEnd(Table t,LL st,char *str,int index);
void freeList(LL list);

#endif
