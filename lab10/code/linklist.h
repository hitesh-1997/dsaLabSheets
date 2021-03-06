#ifndef List_H
#define List_H

struct node{
    int data;
    struct node *next;
};

struct ll{
    struct node *head;
    int size;
};

typedef struct node* Node;
typedef struct ll* LL;

// methods for the stack

extern void insertInFront(LL,int);
extern int deletFromFront(LL st);
extern LL createList();

#endif
