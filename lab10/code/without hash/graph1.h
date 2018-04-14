#ifndef GMAT_H
#define GMAT_H


struct vertex{
	int data;
};

typedef struct vertex *Vertex;

struct graph{
	Vertex *vlist;
	int num;
	int **mat;
};

typedef struct graph *Graph;


int func(Graph g,Vertex v);
Graph create(int num);
int *getAdj(Graph g,Vertex v);
Graph addedge(Graph g,Vertex v,Vertex vadj);
int degree(Graph g,Vertex v);
void bfs(Graph g);
Vertex createv(int data);

#endif
