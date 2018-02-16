#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "mem.h"

    
LL create(){
    LL link = (LL)myalloc(sizeof(struct ll));
    link->head = NULL;
    link->size=0;
    return link;
}

void push(LL st,int i,int j){
    Node n = (Node)myalloc(sizeof(struct node));
    n->first = i;
    n->last = j;
    n->next = st->head;
    st->head= n;
    st->size++;
 //   traverse(st);
}


void pop(LL st){
    if(st->head == NULL)
        return;
    Node ptr = st->head->next;
    st->head = ptr;
    st->size--;
}

Node top(LL st){
    return st->head;
}


void traverse(LL st){
    Node head = st->head;
    while(head){
        printf("stack vales: %d  %d\n",head->first,head->last);
        head = head->next;
    }
    printf("\n");
}

boolean isempty(LL st){
    if(st->head == NULL)
        return true;
    else
        return false;
}
