
#ifndef QUE_H
#define QUE_H

#define ll long long int

//extern int qsize;

#include "tree.h"

struct ele{
	struct node* data;
	struct ele *next;
};

struct queue{
	struct ele *head;
	struct ele *tail;
    int qsize;
};

typedef struct ele *Ele;
typedef struct queue *Queue;

#ifndef BOOLEAN_H
#define BOOLEAN_H
typedef enum {false=0,true=1} boolean;
#endif

Queue newQ();
boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
struct node* front(Queue q);
Queue addQ(Queue q ,struct node* data);
int lengthQ(Queue q);


#endif
