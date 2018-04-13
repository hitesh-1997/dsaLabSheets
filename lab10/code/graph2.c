#include "graph2.h"
#include "linklist.h"
#include "que.h"
#include <stdio.h>
#include <stdlib.h>

int func(Graph g,Vertex v){
	return v->data;
}

Graph create(int num){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->num = num;
	int i;
	g->vlist = (Vertex*)malloc(num*sizeof(Vertex));
	for(i=0;i<num;i++)
		g->vlist[i] = NULL;
	g->elist = (LL*)malloc(num*sizeof(LL));
	for(i=0;i<num;i++){
		g->elist[i] = createList();
	}
	
	/*for(i=0;i<num;i++){
		printf("%d\n",g->elist[i]);
	}*/
	
	return g;
}

LL getAdj(Graph g,Vertex v){ 
	int index = func(g,v);	
	return g->elist[index];
}

Graph addedge(Graph g,Vertex v,Vertex vadj){
	//printf("%d %d\n",v->data,vadj->data);
	int i; 
	i = func(g,v);
	int j = func(g,vadj);
	if(!g->vlist[i])
		g->vlist[i]=v;
	if(!g->vlist[j])
		g->vlist[j]=vadj;
	insertInFront(g->elist[i],j);	
	return g;
}

int degree(Graph g,Vertex v){
	int index = func(g,v);	
	return g->elist[index]->size;
}

void bfs(Graph g){
	int num = g->num;
	int *visited = (int*)malloc(num*sizeof(num));
	int i;
	for(i=0;i<num;i++)
		visited[i]=0;
	Queue q = newQ();
	q = addQ(q,0);
	visited[0]=1;
	while(!isEmptyQ(q)){
		int index = front(q);
		printf("%d	\n",g->vlist[index]->data);
		q = delQ(q);
		Node head = g->elist[index]->head;
		while(head){
			if(!visited[head->data]){
				visited[head->data]=1;	
				q = addQ(q,head->data);
			}
			head= head->next;
		}
	}

}

Vertex createv(int data){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	v->data = data;
	return v;
	
}


int main(){
	
	Graph g = create(10);
	Vertex v0 = createv(0);
	Vertex v1 = createv(1);
	Vertex v2 = createv(2);
	Vertex v3 = createv(3);
	Vertex v4 = createv(4);
	Vertex v5 = createv(5);
	Vertex v6 = createv(6);
	Vertex v7 = createv(7);
	Vertex v8 = createv(8);
	Vertex v9 = createv(9);
	
	g = addedge(g,v0,v1);
	g = addedge(g,v0,v5);
	g = addedge(g,v0,v6);
	g = addedge(g,v1,v7);
	g = addedge(g,v1,v3);
	g = addedge(g,v7,v8);
	g = addedge(g,v8,v9);
	g = addedge(g,v3,v8);
	g = addedge(g,v3,v5);
	g = addedge(g,v5,v9);
	g = addedge(g,v9,v2);
	g = addedge(g,v5,v2);
	g = addedge(g,v6,v5);
	g = addedge(g,v6,v4);
	
	printf("bfs traversal\n");
	
	
	bfs(g);
	
	
}
