#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true} boolean;

struct node{
    int data;
    struct node *next;
};

struct ll{
    struct node *head;
    int size;
};

typedef struct node* Node;
typedef struct ll* LL;

LL createList(){
    int i;
    LL link = (LL)malloc(sizeof(struct ll));
    link->head = NULL;
    link->size=0;
    return link;
}

void insertInFront(LL st,int data){
    Node n = (Node)malloc(sizeof(struct node));
    n->data = data;
    n->next = st->head;
    st->head= n;
    st->size++;
}

struct iterator{
	LL list;
	struct node *ptr;
};

typedef struct iterator *Iterator;

Iterator createit(LL list){
	Iterator it = (Iterator)malloc(sizeof(struct iterator));
	it->list = list;
	it->ptr = list->head;
	
}

boolean hasMore(Iterator it){
	return it->ptr!=NULL;
}

struct node getNext(Iterator it){
	struct node ele = *(it->ptr);
	it->ptr = it->ptr->next;
	return ele;
}

int main(){
	LL list = createList();
	int i;
	for(i=0;i<20;i++)
		insertInFront(list,i);
	Iterator it = createit(list);
	while(hasMore(it))
		printf("%d\n",getNext(it).data);


}




