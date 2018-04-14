#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

LL createList(){
    int i;
    LL link = (LL)malloc(sizeof(struct ll));
    link->head = NULL;
    link->size=0;
    return link;
}

void insertInFront(LL st,int data){
	if(!st)
		printf("*//////////////////\n");
    Node n = (Node)malloc(sizeof(struct node));
    n->data = data;
    n->next = st->head;
    st->head= n;
    st->size++;
}

int deletFromFront(LL st){
    if(st->head == NULL)
        return -2;
    Node head = st->head;
    int value = head->data;
    Node ptr = st->head->next;
    st->head = ptr;
    st->size--;
    return value;
}

