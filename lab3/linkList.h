#ifndef List_H
#define List_H

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

// methods for the stack

void insertInFront(LL);
void insertAtEnd(LL);
int deletFromFront(LL);
int deleteAtEnd(LL);
void traverse(LL);
int hasCycle(LL link);
LL createCycle(LL link);
LL createList(int n);
Node cycleNode(LL link);
LL makecircular(LL link);

#endif
