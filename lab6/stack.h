
#ifndef List_H
#define List_H

struct node{
    int first;
    int last;
    struct node *next;
};

struct ll{
    struct node *head;
    int size;
};

typedef struct node* Node;
typedef struct ll* LL;

typedef enum {false=0,true=1} boolean;

// methods for the stack


LL create();
void push(LL,int i,int j);
void pop(LL);
Node top(LL);
void traverse(LL st);
boolean isempty(LL st);


#endif