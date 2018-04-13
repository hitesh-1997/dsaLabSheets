#include "graph2.h"
#include "linklist.h"
#include "que.h"
#include <stdio.h>
#include <stdlib.h>


int func(Graph g,Vertex v){
	int sz = g->num;
	if(sz==0){
		g->vlist = (Vertex*)malloc(sizeof(Vertex));
		g->elist = (LL*)malloc(sizeof(LL));
		g->vlist[0]=v;
		g->num++;
		g->elist[0] = createList();
		return 0;
	}
	int i=0;
	while(i<sz){
		if(g->vlist[i]->data==v->data){
			return i;	
		}
		i++;
	}
	g->vlist = (Vertex*)realloc(g->vlist,(sz+1)*sizeof(Vertex));
	g->elist = (LL*)realloc(g->elist,(sz+1)*sizeof(LL));
	g->vlist[sz]=v;
	g->num++;
	g->elist[sz] = createList();
	return sz;
}

Graph addedge(Graph g,Vertex v,Vertex vadj){
	//printf("%d %d\n",v->data,vadj->data);
	int i = func(g,v);
	int j = func(g,vadj);
	//printf("i= %d, data= %d, j- %d, data= %d\n",i,v->data,j,vadj->data);
	insertInFront(g->elist[i],j);	
	return g;
}

Vertex createv(int data){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	v->data = data;
	return v;
	
}

void bfs(Graph g){
	int num = g->num;
	int *visited = (int*)malloc(num*sizeof(int));
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
	free(visited);
}

void dfs(Graph g,int *visited,LL list,int v){
	visited[v]=1;
	Node head = g->elist[v]->head;
	while(head){
		if(!visited[head->data])
			dfs(g,visited,list,head->data);
		head= head->next;
	}
	insertInFront(list,g->vlist[v]->data);
}

LL topoSort(Graph g){
	LL list = createList();
	int i;
	int *visited = (int*)malloc((g->num)*sizeof(int));
	for(i=0;i<g->num;i++)
		visited[i]=0;
	for(i=0;i<g->num;i++){
		if(!visited[i])
			dfs(g,visited,list,i);
	}
	return list;	
}

int main(int argv,char **argc){
	FILE *fp = fopen(argc[1],"r");
	if(!fp){
		printf("can't open file\n");
		exit(1);
	}
	int x,y;
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->num=0;
	while(fscanf(fp,"%d %d\n",&x,&y)==2){
		Vertex v1 = createv(x);
		Vertex v2 = createv(y);
		g = addedge(g,v1,v2);
	}			
	int i;
	printf("printing adj vertex:\n");
	for(i=0;i<g->num;i++){
		printf("for i= %d vertex is= %d\n",i,g->vlist[i]->data);
	}

	printf("\ntraversing bfs\n");
	bfs(g);
	LL list = topoSort(g);
	
	printf("\nprinting topological sorted vertices:- \n");
	Node head = list->head;
	while(head){
		printf("%d	",head->data);
		head=head->next;
	}
	printf("\n");
}




