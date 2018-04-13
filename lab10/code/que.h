
#ifndef QUE_H
#define QUE_H

//extern int qsize;

struct element{
	int data;
	struct element *next;
};

struct queue{
	struct element *head;
	struct element *tail;
    int qsize;
};

typedef struct element *Element;
typedef struct queue *Queue;
typedef enum {false=0,true=1} boolean;


Queue newQ();
boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
int front(Queue q);
Queue addQ(Queue q ,int data);
int lengthQ(Queue q);


#endif
