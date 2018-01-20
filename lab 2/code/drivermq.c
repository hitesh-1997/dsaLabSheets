#include "MultiQ.h"
#include "que.h"
#include <stdio.h>
#include <stdlib.h>

void printmq(MultiQ mq);
void print(Queue q);

int main(){
    Task *arr;
	arr = (Task *)malloc(20*sizeof(Task));
	for(int i=0;i<20;i++){
		arr[i] = (Task)malloc(sizeof(task));
		arr[i]->data = i+1;
        arr[i]->pr = (2*i*i+i/5+i*96+8*9)%5;
	}
	printf("printing the elements \n");
	for(int i=0;i<20;i++){
		printf("data for i= %d is = %d  and prio = %d\n",i,arr[i]->data,arr[i]->pr);
	}
	printf("creating mq\n");
	MultiQ mq = createMQ(5);
    printf("adding elements\n");
    for(int i=0;i<20;i++){
        mq = addMQ(mq,arr[i]);
	}
	printmq(mq);
    printf("len of queue with prior 2 = %d\n",sizeMQbyPriority(mq,2));
    printf("total items in qqueue = %d\n",sizeMQ(mq));
    printf("are all queues empty = %d\n",isEmptyMQ(mq));
    printf("receving q with max pr\n");
    Queue q = getQueueFromMQ(mq,4);
    printf("front with max pr:- %d\n",front(q)->data);
    printf("front with max pr:- %d\n",nextMQ(mq)->data);
    print(q);
    printf("asdfgh  %d\n",isEmptyQ(q));
    
    printmq(mq);
    
    
    printf("deleting max element\n");
    mq = delNextMQ(mq);
    print(q);
    mq = delNextMQ(mq);
    print(q);
    mq = delNextMQ(mq);
    print(q);
    mq = delNextMQ(mq);
    print(q);
    mq = delNextMQ(mq);
    print(q);
    mq = delNextMQ(mq);
    
    printmq(mq);
    
    
}

void printmq(MultiQ mq){
    printf("\n*****   starting printing multiple queue    ***********\n");
    for(int i=0;i<mqsize;i++){
        printf("queue of the prriority = %d is: \n",i);
        print(mq[i]);
        printf("\n");
    } 
    printf("\n*****   finished printing multiple queue    ***********\n");
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
