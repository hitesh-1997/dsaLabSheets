#include "MultiQ.h"
#include "mem.h"
#include "que.h"
#include <stdio.h>
#include <stdlib.h>


MultiQ createMQ(int num){
	totalsize=0;
    mqsize = num;
	MultiQ mq = (MultiQ)myalloc(num*sizeof(Queue));
    int i;
    for(i=0;i<num;i++){
        mq[i] = newQ();
    }
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
	Queue q = mq[t->pr];
	q = addQ(q,t);
    totalsize++;
	return mq;
}

Task nextMQ(MultiQ mq){
	return front(mq[mqsize-1]);
}

MultiQ delNextMQ(MultiQ mq){
    int val = isEmptyQ(mq[mqsize-1]);
    //printf("received value = %d",val);
    if(val==0){
        totalsize--;
        Task t = nextMQ(mq);
        mq[mqsize-1] = delQ(mq[mqsize-1]);
    }
    return mq;
}

int isEmptyMQ(MultiQ mq){
    return (totalsize==0);
}

int sizeMQ(MultiQ mq){
    return totalsize;
}

int sizeMQbyPriority(MultiQ mq, int p){
    return lengthQ(mq[p]);
}

Queue getQueueFromMQ(MultiQ mq,int p){
    return mq[p];
}
