#include "MultiQ.h"
#include "que.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

MultiQ testDel(MultiQ mq,int num);
MultiQ loadData(FILE*);
void printmq(MultiQ mq);
void print(Queue q);

int main(){
    FILE *fp;
    fp = fopen("input10000.txt","r");
    if(fp==NULL){
        printf("file not loaded\n");
        exit(1);
    }
    struct timeval t1,t2;
    float elaptime;
    gettimeofday(&t1,NULL);
    MultiQ mq = loadData(fp);
    gettimeofday(&t2,NULL);
    elaptime = (t2.tv_usec-t1.tv_usec)/1000.0; //1000.0 point to con. to float
    printf("load function time in mil sec = %f\n",elaptime);
    //printmq(mq);
    printf("max pr elemets len = %d\n",sizeMQbyPriority(mq,9));
    printf("\n ***** deleting elements **** \n");
    gettimeofday(&t1,NULL);
    mq = testDel(mq,9788);
    gettimeofday(&t2,NULL);
    elaptime = (t2.tv_usec-t1.tv_usec)/1000.0;
    printf("testDel function time in mil sec = %f\n",elaptime);
    printf("after deletion max pr elemets len = %d,\n",sizeMQbyPriority(mq,9));
    printf("total heap size used: - %d\n",heap);
    //printmq(mq);
}

MultiQ loadData(FILE *fp){
    MultiQ mq = createMQ(10);
    char line[100];
    char delim[2];
    char num1[50];
    char num2[5];
    delim[0]=',';
    delim[1]='\0';
    int count=0,x,y;
    Task t;
    while(fgets(line,sizeof(line),fp)!=NULL){
        strcpy(num1,strtok(line,delim));
        strcpy(num2,strtok(NULL,delim));
        t = (Task)myalloc(sizeof(task));
        //printf("%s and pr = %s\n",num1,num2);
        t->data = atoi(num1);
        t->pr = atoi(num2)-1;
        //printf("numers= %d and %d: \n",x,y);
        mq = addMQ(mq,t);
    }
    //printf("\n%d",count);
    return mq;
}

MultiQ testDel(MultiQ mq,int num){
    int i;
    for(i=0;i<num;++i){
        mq = delNextMQ(mq);
    }
    return mq;
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
