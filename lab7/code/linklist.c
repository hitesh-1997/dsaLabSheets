#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

LL createList(){
    LL link = (LL)myalloc(sizeof(struct ll));
    link->head = NULL;
    link->size=0;
    return link;
}

Table insertAtEnd(Table t,LL st,char *str,int index){ // returns the insertion cost
    
    Node n = (Node)myalloc(sizeof(struct node));
    Record rec = (Record)myalloc(sizeof(struct record));
    rec->name = str;
    n->data = rec;
    n->index=index;
    n->cnt=1;
    Node head = st->head;
    Node p;
    int count=0;
    if(!head){
        head=n;
    }
    else{
        Node ptr = st->head;
        while(ptr->next != NULL){
        	if(!strcmp(str,ptr->name)){
        		ptr->data->cnt++;
        		free(rec->data);
        		free(rec);
        		free(n);
        		t->inscost+=count;
        		return;
        	} // handle dulicate case
        		
            p=ptr;
            ptr = ptr->next;
            ++count;
        }
        ptr->next = n;
    }
    t->inscost+=count;
    t->elecount++;
    return t;
}

void freeList(LL list){

	Node head = list->head;
	Node prev;
    while(head){
    	prev = head;
        head = head->next;
        if(prev->data->name)
        	myfree(prev->data->name);
        myfree(prev->data);
        myfree(prev);
    }
    myfree(list);
}


/*
void insertInFront(LL st,struct record *data){
    Node n = (Node)malloc(sizeof(struct node));
    n->data = data;
    n->next = st->head;
    st->head= n;
    st->size++;
}
*/

/*
int deleteAtEnd(LL st){
    if(st->head == NULL)
        return -2;
    Node ptr = st->head;
    Node head = st->head;
    Node p=NULL;
    while(ptr->next != NULL){
        p=ptr;
        ptr = ptr->next;
    }
    if(ptr==head)
        head=NULL;
    else
        p->next=NULL;
    return ptr->data;
}
*/
/*
void traverse(LL st){
    if(hasCycle(st)){
        Node ptr = cycleNode(st);
        Node temp = ptr;
        do{
            printf("%d  ",temp->data);
            temp = temp->next;
        }while(ptr!=temp);
        printf("\n");
        return;
    }
    
    Node head = st->head;
    while(head){
        printf("%d  ",head->data);
        head = head->next;
    }
    printf("\n");
}

*/

/*

void deletFromFront(LL st){
    if(st->head == NULL)
        return -2;
    Node head = st->head;
    int value = head->data;
    Node ptr = st->head->next;
    st->head = ptr;
    st->size--;
}

*/
