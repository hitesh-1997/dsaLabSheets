#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

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
	else if(hei(root->left)<hei(root->right))
		return -1;
	else 
		return 0;
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

struct node *insert(struct node *root,int data){
	if(!root)
		return createnode(data);
	else if(root->val->data==data) // not inserting duplicates
		return root;
	else if(root->val->data > data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	
	root->height = max(hei(root->left),hei(root->right))+1;
	root->balance = balance(root);
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
	if(!root){
		return root;
	}
	else if(root->val->data > data){
		root->left = delete(root->left,data);
		root->height = max(hei(root->left),hei(root->right))+1;
		root->balance = balance(root);
	}
	else if(root->val->data < data){
		root->right = delete(root->right,data);
		root->height = max(hei(root->left),hei(root->right))+1;
		root->balance = balance(root);
	}
	else{
		printf("entered else \n");
		if(!root->left||!root->right){
			struct node *temp = (root->left)?root->left:root->right;
			if(!temp){
				free(root);
				root=NULL;
			}	
			else{
			//	printf("temo data is: -%d\n",temp->val->data);
				free(root);
				root=temp;
			}
		}
		else{
			struct node *temp = findmin(root->right);
			//printf("min value found is= %d\n",temp->val->data);
			root->val->data = temp->val->data;
			root->right = delete(root->right,temp->val->data);
			root->height = max(hei(root->left),hei(root->right))+1;
			root->balance = balance(root);
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

struct node* inorder(struct node *root,int k){
	if(!root)
		return NULL;
	static int count=0;
	struct node *temp = inorder(root->left,k);
	++count;
	if(count==k){
		temp=(temp)?temp:root;
	}
	struct node *var = inorder(root->right,k);
	temp = (var)?var:temp;
	return temp;
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
	int i;
	
	tree = insert(tree,60);
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
	
	/*struct node *temp = inorder(tree,16);
	if(!temp){
		printf("out of range\n");
	}
	else
		printf("value is= %d\n",temp->val->data);
	*/
	range(tree,8,60);
	
	/*
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

























