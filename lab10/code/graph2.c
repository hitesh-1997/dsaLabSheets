#include "que.h"
#include "graph2.h"

#include <stdio.h>
#include <stdlib.h>

int current = 0;


Graph create(int num){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->num = num;
	int i;
	g->vlist = createTable(2*num);
	g->elist = (LL*)malloc(num*sizeof(LL));
	g->arr = (struct record**)malloc(num*sizeof(struct record*));
	for(i=0;i<num;i++)
		g->arr[i] = NULL;
	for(i=0;i<num;i++)
		g->elist[i] = createList();
	return g;
}

LL getAdj(Graph g,char *key){ 
	int index = findKey(g->vlist,key);	
	return g->elist[index];
}

Graph addedge(Graph g,char *k1,char *k2){
	//printf("%d %d\n",v->data,vadj->data);
	int x = insertRec(g->vlist,k1,current);
	if(x!=-1){
		
		current++;
	}
	int y = insertRec(g->vlist,k2,current);
	if(y!=-1){
		
		current++;
	}
	//printf("x= %d and y= %d\n",x,y);
	
	int i = findKey(g->vlist,k1);
	if(!g->arr[i])
		g->arr[i] = g->vlist->list[x];
	int j = findKey(g->vlist,k2);
	//printf("values i= %d, j= %d\n",i,j);
	if(!g->arr[j])
		g->arr[j] = g->vlist->list[y];
	//printf("values i= %d, j= %d\n",i,j);
	if(i!=-1&&j!=-1)
	insertInFront(g->elist[i],j);	
	return g;
}

int degree(Graph g,char* key){
	int index = findKey(g->vlist,key);
	return g->elist[index]->size;
}

void bfs(Graph g,int numred){
	int num = g->num;
	int *visited = (int*)malloc(num*sizeof(num));
	int i;
	for(i=0;i<num;i++)
		visited[i]=0;
	Queue q = newQ();
	q = addQ(q,numred);
	visited[numred]=1;
	while(!isEmptyQ(q)){
		int index = front(q);
		printf("%s	",g->arr[index]->key);
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

int main(){
	
	/*	
	Graph g = create(10);
	
	char v0[15] = "alice";
	char v1[15] = "bob";
	char v2[15] = "hitesh";
	char v3[15] = "demigod";
	char v4[15] = "adam";
	char v5[15] = "fire";
	char v6[15] = "gun";
	char v7[15] = "hyphen";
	char v8[15] = "intercom";
	char v9[15] = "jungle";



	char v0[15] = "a";
	char v1[15] = "b";
	char v2[15] = "c";
	char v3[15] = "d";
	char v4[15] = "e";
	char v5[15] = "f";
	char v6[15] = "g";
	char v7[15] = "h";
	char v8[15] = "i";
	char v9[15] = "j";
	
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
	*/
	/*int i;
	for(i=0;i<g->num;i++)
		printf("vertex i= %d key= %s\n",i,g->arr[i]->key);
	*/
	
	
	FILE *fp = fopen("input.txt","r");
	if(!fp){
		printf("can't open file\n");
		exit(1);
	}
	int num;
	fscanf(fp,"%d\n",&num);
	printf("num is- %d\n",num);
	Graph g = create(num);
	
	char str[150];
	char str1[150];
	char str2[150];	
	while(fscanf(fp,"%149[^\n]\n",str)!=EOF){
		//printf("%s\n",str);
		sscanf(str,"%*[^=]=%*[^=]=%149[^;];%*[^=]=%149[^;];",str1,str2);
		//printf("str1 = %s\n str2= %s\n",str1,str2);
		g = addedge(g,str1,str2);
		
	}
	
	printf("bfs traversal\n");
	int i;
	for(i=0;i<10;i++){
		bfs(g,i);
		printf("\n************************\n");
	}
	
}
