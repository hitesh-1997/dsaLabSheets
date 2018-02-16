#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"
#include "mem.h"

//#define ll long long int


int main(){
    printf("size of struct node is :- %zu\n",sizeof(struct node));
    unsigned long long int n;
    n = 29999999;
    //n = 10;
    printf("size of link= %zu\n",sizeof(struct node));
    LL link = createList(n);
    printf("list created:- \n");
    //traverse(link);
   /* printf("deleted:- %d\n",deletFromFront(link));
    printf("deleted:- %d\n",deletFromFront(link));
    printf("deleted:- %d\n",deletFromFront(link));
    printf("deleted:- %d\n",deletFromFront(link));
    printf("deleted:- %d\n",deletFromFront(link));
    printf("deleted at end///:- %d\n",deleteAtEnd(link));
    printf("deleted at end///:- %d\n",deleteAtEnd(link));
    printf("deleted at end///:- %d\n",deleteAtEnd(link));
    printf("deleted at end///:- %d\n",deleteAtEnd(link));
    printf("deleted at end///:- %d\n",deleteAtEnd(link));
    printf("deleted at end///:- %d\n",deleteAtEnd(link));*/
  
    
    link = createCycle(link);
    printf("\n does linked list have cycle: %d\n",hasCycle(link));
    //traverse(link);
    printf("before making list circular heap used:- %d\n",heap);
    printf("making linked list circular\n");
    makecircular(link);
    printf("after making list circular heap used:- %d\n",heap);
    // for each node sizeof(struct node) i.e 16 + size of(ull) i.e. 8 cleared
    //traverse(link);
    
}

