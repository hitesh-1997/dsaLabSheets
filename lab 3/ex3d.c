#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"
#include "mem.h"

//#define ll long long int


int main(){
    unsigned long long int n = 29999999;
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
    
}

