#ifndef TREE_H
#define TREE_H


#ifndef BOOLEAN_H
#define BOOLEAN_H
typedef enum {false=0,true=1} boolean;
#endif


struct element{
	int data;
};

typedef struct element *Element;

struct iterator{
	struct node **list;
	int size;
	int count;
};

typedef struct iterator *Iterator;

struct node{
	struct element *val;
	Iterator it;
};

typedef struct node *Node;


Iterator createit(struct node **list,int sz);
boolean hasMore(Iterator it);
struct node *nextEle(Iterator it);
struct node *createnode(int value);
struct node *createTree(int num,int depth);
boolean isEmptyTree(Node tree);
struct element *getRootVal(Node tree);
Iterator getChildren(Node tree);
void BFT(struct node *tree);

#endif 