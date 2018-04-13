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

int func(Graph g,Vertex v);
Graph create(int num);
LL getAdj(Graph g,Vertex v);
Graph addedge(Graph g,Vertex v,Vertex vadj);
int degree(Graph g,Vertex v);
void bfs(Graph g);

#endif
