#include "que.h"
#include <stdio.h>
#include <stdlib.h>

/*
  handle cases when head is null
*/

//static int qsize;

Queue newQ(){
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->head = NULL;
	q->tail = NULL;
	q->qsize=0;
	return q;
}

boolean isEmptyQ(Queue q){
    if(q->head==NULL){
       // printf("head is null\n");
        return true;
    }
    else{
        //printf("head is not null");
        return false;
    }
    
}

Queue delQ(Queue q){
	Element head = q->head;
	Element tail = q->tail;
  /*  Element ptr = head;
    printf("\n ************* \n");
    while(ptr){
		printf("%d  ",ptr->data);
		ptr = ptr->next;
	}*/
	if(!head)
		return q;
	if(head->next == NULL){
       // printf("11111111111111111111111\n");
		q->head = NULL;
		q->tail = NULL;
		q->qsize--;	
	}
	else{
		q->qsize--;
		q->head = q->head->next;	
	}
	return q;
}

int front(Queue q){
	return q->head->data;
}

Queue addQ(Queue q ,int data){
	Element e = (Element)malloc(sizeof(struct element));
	e->data = data;
	e->next = NULL;
	//printf("elment received add: %d\n",e->data);
	Element head = q->head;
	Element tail = q->tail;
	if(!head){
		//printf("head is null\n");
		q->head = e;
		q->tail = e;
	}
	else{
		//printf("in else statement\n");
		q->tail->next = e;
		q->tail = e;
	}
	q->qsize++;
	return q;
}

int lengthQ(Queue q){
	/*Element head = q->head;
	Element tail = q->tail;
	int size=0;
	while(head != tail){
		size++;
		head = head->next;	
	}
	return (++size);*/
	return q->qsize;
}
