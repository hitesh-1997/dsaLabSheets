#include <stdio.h>
#include <stdlib.h>
#include "que.h"

void print(Queue q);

int main(){
	Element *arr;
	arr = (Element *)malloc(10*sizeof(Element));
	for(int i=0;i<10;i++){
		arr[i] = (Element)malloc(sizeof(struct element));
		arr[i]->data = i+1;
	}
	printf("printing the elements \n");
	for(int i=0;i<10;i++){
		printf("%d  ",arr[i]->data);
	}

	printf("printing finished\n");
	printf("creating a queue\n");
	Queue q = newQ();
	printf("is queue empty: %d\n",isEmptyQ(q));
	q = addQ(q,arr[1]);
	q = addQ(q,arr[2]);
	print(q);
	q = addQ(q,arr[3]);
	print(q);	
	q = addQ(q,arr[4]);
	print(q);
	q = addQ(q,arr[5]);
	q = addQ(q,arr[6]);				
	print(q);
	printf("*********************************\n");
	print(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	q = delQ(q);
	print(q);
	printf("front element is = \n");
	printf("%d",front(q)->data);
	printf("length is \n");
	printf("%d",lengthQ(q));
	
}

void print(Queue q){
	Element head = q->head;
	if(q->head == NULL){
		printf("empty queue\n");
		return;	
	}
	printf("printing elements of queue head = %d\n",head->data);	
	while(head){
		printf("%d  ",head->data);
		head = head->next;
	}
	printf("finished printing\n");
}
