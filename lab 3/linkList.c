#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"
#include "mem.h"

LL createList(int n){
    int i;
    LL link = (LL)myalloc(sizeof(struct ll));
    link->head = NULL;
    link->size=0;
    printf("size before allocating nodes- %d\n",maxheap);
    for(i=0;i<n;i++){
        insertInFront(link);
        //printf("size during allocating nodes- %d\n",maxheap);
    }
    printf("size after allocating nodes- %d\n",maxheap);
    return link;
}

void insertInFront(LL st){
    Node n = (Node)myalloc(sizeof(struct node));
    n->data = rand()%50000;
    n->next = st->head;
    st->head= n;
    st->size++;
 //   traverse(st);
}

void insertAtEnd(LL st){
    Node n = (Node)myalloc(sizeof(struct node));
    n->data = rand()%50000;
    Node head = st->head;
    Node p;
    if(!head){
        head=n;
    }
    else{
        Node ptr = st->head;
        while(ptr->next != NULL){
            p=ptr;
            ptr = ptr->next;
        }
        ptr->next = n;
    }
    traverse(st);
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

int hasCycle(LL link){
    if(link->head == NULL)
        return 0;
    Node hare = link->head;
    Node tor = link->head;
    do{
        if(hare->next == NULL || tor->next==NULL || tor->next->next==NULL)
            return 0;
        hare = hare->next;
        tor = tor->next->next;
    }while(hare!=tor);
    return 1;
}

LL createCycle(LL link){
    int ch = rand()%2;
    printf("random for cycle= %d\n",ch);
    if(ch){
        printf("cycle not created\n");
        return link;
    }
    int n = link->size;
    int r = rand()%n;
    Node head = link->head;
    Node ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    Node ptr2 = head;
    for(int i=0;i<r;i++)
        ptr2=ptr2->next;
    ptr->next = ptr2;
    return link;
}

Node cycleNode(LL link){
    if(link->head == NULL)
        return NULL;
    Node hare = link->head;
    Node tor = link->head;
    do{
        if(hare->next == NULL || tor->next==NULL || tor->next->next==NULL)
            return NULL;
        hare = hare->next;
        tor = tor->next->next;
    }while(hare!=tor);
    return hare;
}

LL makecircular(LL link){
    Node head = link->head;
    Node ptr = head;
    if(!hasCycle(link)){
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = head;
        return link;
    }
    Node temp = cycleNode(link);
    while(ptr->next != temp->next){
        Node curr = ptr;
        ptr = ptr->next;
        temp = temp->next;
        myfree(curr);
    }
    link->head = ptr->next;
    ptr->next = NULL;
    myfree(ptr);
    return link;
}


