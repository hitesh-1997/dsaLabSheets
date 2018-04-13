#ifndef AVLTREE_H
#define AVLTREE_h


struct element{
	int data;

};

typedef struct element *Element;

struct node{
	Element val;
	struct node *left;
	struct node *right;
	int height;
	int balance:2;
};


struct node *insert(struct node *root,int data);
struct node *find(struct node *root,int data);
struct node *delete(struct node *root,int data);

#endif 


