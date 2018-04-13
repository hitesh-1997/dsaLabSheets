#include "graph1.h"
#include "que.h"
#include <stdio.h>
#include <stdlib.h>

int func(Graph g,Vertex v){
	return v->data;
}


Graph create(int num){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->num = num;
	g->vlist = (Vertex*)malloc(num*sizeof(Vertex));
	g->mat = (int**)malloc(num*sizeof(int*));
	int i,j;
	for(i=0;i<num;i++)
		g->mat[i] = (int*)malloc(num*sizeof(int));		
	for(i=0;i<num;i++)
		g->vlist[i]=NULL;	
	/*for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			g->mat[i][j]=0;
	*/
	return g;
}

int *getAdj(Graph g,Vertex v){ // -1 is returned to denote eof array
	int *arr=(int*)malloc((g->num)*sizeof(int));
	int i,k=0;
	int index = func(g,v);
	for(i=0;i<g->num;i++){
		if(g->mat[index][i])
			arr[k++]=i;
	}
	arr[k]=-1;
	arr = (int*)realloc(arr,(k+1)*sizeof(int));
	return arr;
}

Graph addedge(Graph g,Vertex v,Vertex vadj){
	int i = func(g,v);
	int j = func(g,vadj);
	//printf("adding edge between- %d %d\n",i,j);
	g->mat[i][j]=1; 
	if(!g->vlist[i])
		g->vlist[i]=v;
	if(!g->vlist[j])
		g->vlist[j]=vadj;
	return g;
}

int degree(Graph g,Vertex v){
	int i,sum=0;
	int index = func(g,v);
	for(i=0;i<g->num;i++)
		if(g->mat[index][i])
			sum++;
	return sum;
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
	
	
	int i,j;
	/*printf("\n");
	for(i=0;i<g->num;i++){
		printf("%d	",i);
	}
	printf("\n");
	for(i=0;i<g->num;i++){
		printf("\n");
		printf("%d->  ",i);
		for(j=0;j<g->num;j++)
			printf("%d	",g->mat[i][j]);
	}
	*/
	printf("\n");
	printf("\n**** bfs traversal ****\n");
	
	bfs(g);
	
	printf("\n");
	
	
	
	
	
}
