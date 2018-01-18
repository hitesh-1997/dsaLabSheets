#ifndef MULQUE_H
#define MULQUE_H
#include "que.h"

int totalsize;
int mqsize;

typedef Queue *MultiQ;
typedef Element Task;
typedef struct element task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int p);
Queue getQueueFromMQ(MultiQ,int p);


#endif
