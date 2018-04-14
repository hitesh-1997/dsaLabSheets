#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

#define COUNT 10
 
int hei(struct node *root){
	if(!root)
		return 0;
	else 
		return root->height;
}

int max(int x,int y){
	return (x>y)?x:y;
}

int balance(struct node *root){
	if(hei(root->left)<hei(root->right))
		return 1;
	else if(hei(root->left)>hei(root->right))
		return -1;
	else 
		return 0;
}

int getbal(struct node *root){
	if(!root)
		return 0;
	return
		hei(root->left)-hei(root->right);
}

void update(struct node *root){
	root->height = max(hei(root->left),hei(root->right))+1;
	root->balance = balance(root);
}

struct node *findmin(struct node *root){
	struct node *ptr = root;
	while(ptr->left)
		ptr = ptr->left;
	return ptr;
}

struct node *createnode(int data){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	Element ele = (Element)malloc(sizeof(struct element));
	ele->data = data;	
	ptr->val = ele;
	ptr->left=ptr->right=NULL;
	ptr->height=1;
	ptr->balance=0;
	return ptr;
}


struct node *rotR(struct node *root){
	struct node *y = root->left;
	struct node *t3 = y->right;
	root->left = t3;
	y->right = root;
	update(root);
	update(y);
	return y;
}

struct node *rotL(struct node *root){
	struct node *y = root->right;
	struct node *t3 = y->left;
	root->right = t3;
	y->left = root;
	update(root);
	update(y);
	return y;
}

struct node *insert(struct node *root,int data){
	if(!root)
		return createnode(data);
	else if(root->val->data==data) // not inserting duplicates
		return root;
	else if(root->val->data > data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	update(root);
	
	int bal = getbal(root);
	if(bal>1){
		if(root->left->val->data>=data)
			root = rotR(root);
		else{
			root->left = rotL(root->left);
			root = rotR(root);
		}
	}
	else if(bal<-1){
		if(root->right->val->data<data)
			root = rotL(root);
		else{
			root->right = rotR(root->right);
			root = rotL(root);
		}
	}
	return root;
}


struct node *find(struct node *root,int data){
	if(!root)
		return NULL;
	else if(root->val->data==data)
		return root;
	else if(root->val->data > data)
		return find(root->left,data);
	else 
		return find(root->right,data);
}

struct node *delete(struct node *root,int data){
	if(!root)
		return root;
	else if(root->val->data > data)
		root->left = delete(root->left,data);
	else if(root->val->data < data)
		root->right = delete(root->right,data);
	else{
		//printf("entered else \n");
		if(!root->left||!root->right){
			struct node *temp = (root->left)?root->left:root->right;
			free(root);
			if(!temp)				
				root=NULL;
			else
				root=temp;
		}
		else{
			struct node *temp = findmin(root->right);
			root->val->data = temp->val->data;
			root->right = delete(root->right,temp->val->data);
		}
	}
	if(!root) return NULL;
	update(root);
	int bal = getbal(root);
	if(bal>1){
		if(getbal(root->left)>=0)
			root = rotR(root);
		else if(getbal(root->left)<0){
			root->left = rotL(root->left);
			root = rotR(root);
		}
	}
	else if(bal<-1){
		if(getbal(root->right)<=0)
			root = rotL(root);
		else if(getbal(root->right)>0){
			root->right = rotR(root->right);
			root = rotL(root);
		}
	}
	return root;
}

int randomfun(int x,int y){ // x <=y
	return x+(rand()%(y-x+1));
}

void preorder(struct node *root){
	if(!root)
		return;
	printf("val = %d, height= %d, balance= %d\n",root->val->data,root->height,root->balance);
	preorder(root->left);
	preorder(root->right);
	
}

void print(struct node *root, int space)
{
    if (root == NULL)
        return;
 	space += COUNT;
 	print(root->right, space);
 	printf("\n");
	int i;
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d (%d)\n", root->val->data,root->height);
    print(root->left, space);
}


void range(struct node *root,int l,int r){
	if(!root)
		return;
	int data = root->val->data;
	//printf("data is: - %d\n",data);
	if(data>r)
		range(root->left,l,r);
	else if(data<l)
		range(root->right,l,r);
	else{
		printf("%d	",root->val->data);
		range(root->left,l,data-1);
		range(root->right,data+1,r);
	}
}



int main(){
	
	struct node *tree=NULL;
	tree = insert(tree,120);
	tree = insert(tree,25);
	tree = insert(tree,30);
	tree = insert(tree,40);
	tree = insert(tree,50);
	tree = insert(tree,20);
	tree = insert(tree,10);
	tree = insert(tree,90);
	tree = insert(tree,35);
	tree = insert(tree,65);
	tree = insert(tree,5);
	tree = insert(tree,2);
	tree = insert(tree,48);
	tree = insert(tree,37);
	tree = insert(tree,55);
	// printf("printing tree:- \n");
	print(tree,0);
	printf("printing values\n");
	range(tree,8,60);
	printf("\n");
	
	/*tree = delete(tree,60);
	tree = delete(tree,90);
	tree = delete(tree,48);
	tree = delete(tree,55);
	tree = delete(tree,25);
	
	printf("\n\nprinting tree after deletion:- \n");
	print(tree,0);
	
	
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	/*
	int i;
	for(i=0;i<100;i++){
		int val = randomfun(150,170);
		//printf("value generated = %d\n",val);
		tree = insert(tree,val);
	}
	preorder(tree);
	if(find(tree,159))
		printf("found\n");
	else
		printf("not found\n");
	tree = delete(tree,159	);
	if(!tree)
		printf("hfskjhvkjksdjkvbjk\n");
	preorder(tree);
	*/
}

























