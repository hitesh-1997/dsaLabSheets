#ifndef QUE_H
#define QUE_H

//extern int qsize;

struct element{
	int data;
    int pr;
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
Element front(Queue q);
Queue addQ(Queue q , Element e);
int lengthQ(Queue q);


#endif
