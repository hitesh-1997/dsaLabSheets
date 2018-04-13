#ifndef GRAPH2_H
#define  GRAPH2_H

#include "linklist.h"

struct vertex{
	int data;
};

typedef struct vertex *Vertex;

struct graph{
	int num;
	Vertex *vlist;
	LL *elist;
};
typedef struct graph *Graph;

#endif
