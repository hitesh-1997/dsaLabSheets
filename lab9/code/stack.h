#ifndef STACK_H
#define STACK_H

#include "tree.h"

struct nd{
    struct node* first;
    struct nd *next;
};

struct stack{
    struct nd *head;
    int size;
};

typedef struct nd* Nd;
typedef struct stack* Stack;
// methods for the stack


Stack createSt();
void push(Stack,struct node* i);
void pop(Stack);
struct node* top(Stack);
void traverse(Stack st);
int isempty(Stack st);


#endif
