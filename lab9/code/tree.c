#include "tree.h"
#include "que.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define max 3 // max depth = 4

Iterator createit(struct node **list,int sz){
	Iterator it = (Iterator)malloc(sizeof(struct iterator));
	it->size=sz;
	it->count=0;
	it->list = list;
	return it;
}

boolean hasMore(Iterator it){
	return (it->count!=it->size);
}

struct node *nextEle(Iterator it){
	struct node *elem = it->list[it->count];
	it->count++;
	return elem;
}

struct node *createnode(int value){
	Node temp = (Node)malloc(sizeof(struct node));
	temp->val = (Element)malloc(sizeof(struct element));
	temp->val->data = value;
	return temp;
}

struct node *createTree(int num,int depth){ // intial depth 0
	if(depth==max)
		return NULL;
	static int value = 0;
	++value;
	struct node *temp = createnode(value);	
	struct node **list = (struct node**)malloc(num*sizeof(struct node));
	int i;
	for(i=0;i<num;i++)
		list[i] = createTree(num,depth+1);
	temp->it = createit(list,num);
	return temp;
}

boolean isEmptyTree(Node tree){
	return tree==NULL;
}

struct element *getRootVal(Node tree){
	return tree->val;
}

Iterator getChildren(Node tree){
	return tree->it;
}

void BFT(struct node *tree){
	Queue q = newQ();
	addQ(q,tree);
	while(!isEmptyQ(q)){
		struct node *ptr = front(q);
		delQ(q);
		printf("%d	",getRootVal(ptr)->data);
		Iterator it = getChildren(ptr);
		while(hasMore(it)){
			struct node *temp = nextEle(it);
			if(!isEmptyTree(temp))
				addQ(q,temp);
		}
	}
}

void DFT(struct node *tree){
	Stack q = createSt();
	push(q,tree);
	while(!isempty(q)){
		struct node *ptr = top(q);
		pop(q);
		printf("%d	",getRootVal(ptr)->data);
		Iterator it = getChildren(ptr);
		while(hasMore(it)){	
			struct node *temp = nextEle(it);
			if(!isEmptyTree(temp))
				push(q,temp);
		}
	}
}

int main(){
	// 3 is no of child of each node
	struct node *tree = createTree(3,0);
	/*
	printf("\n ***** BFT *****\n");
	BFT(tree);
	printf("\n");
	*/
	printf("\n ***** DFT *****\n");
	DFT(tree);
	printf("\n");

}
