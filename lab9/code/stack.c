#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

    
Stack createSt(){
    Stack link = (Stack)malloc(sizeof(struct stack));
    link->head = NULL;
    link->size=0;
    return link;
}

void push(Stack st,struct node *i){
    Nd n = (Nd)malloc(sizeof(struct nd));
    n->first = i;
    n->next = st->head;
    st->head= n;
    st->size++;
 //   traverse(st);
}


void pop(Stack st){
    if(st->head == NULL)
        return;
    Nd ptr = st->head->next;
    st->head = ptr;
    st->size--;
}

struct node* top(Stack st){
    return st->head->first;
}


void traverse(Stack st){
    Nd head = st->head;
    while(head){
        head = head->next;
    }
    printf("\n");
}

int isempty(Stack st){
    if(st->head == NULL)
        return true;
    else
        return false;
}
