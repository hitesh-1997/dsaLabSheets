#include "hash.h"
#include "mem.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAXIMUM 0x7fffffff

LL createList(){
    LL link = (LL)myalloc(sizeof(struct ll));
    link->head = NULL;
    link->size=0;
    return link;
}

Table insertAtEnd(Table t,LL st,char *str,int index){ // returns the insertion cost
   // printf("string received:- %s\n",str);
    Node n = (Node)myalloc(sizeof(struct node));
    n->next=NULL;
    Record rec = (Record)myalloc(sizeof(struct record));
    rec->name = str;
    rec->index=index;
    rec->cnt=1;
    n->data = rec;
    Node head = st->head;
    Node p;
    int count=0;
    if(!head){
        st->head=n;
    }
    else{
        Node ptr = st->head;
        while(ptr){
        	if(!strcmp(str,ptr->data->name)){
        		ptr->data->cnt++;
        		myfree(rec);
        		myfree(n);
        		t->inscost+=count;
        		return;
        	} // handle dulicate case
        		
            p=ptr;
            ptr = ptr->next;
            ++count;
        }
        ptr=p;
        ptr->next = n;
    }
    t->inscost+=count;
    t->elecount++;
    return t;
}

void freeList(LL list){

	Node head = list->head;
	Node prev;
    while(head){
    	prev = head;
        head = head->next;
        if(prev->data->name)
        	myfree(prev->data->name);
        myfree(prev->data);
        myfree(prev);
    }
    myfree(list);
}

int max(int x,int y){
        return (x>y)?x:y;
}

int hashfun(char *str,int base,int table)
{
	int i,sum=0;
	int len = strlen(str);
	for(i=0;i<len;i++){
		//printf("%lld\n",sum);
		sum+=(31*sum+str[i])%base%table;
	}
	return (sum&MAXIMUM)%base%table; 
	
}

int collisioncount(char **arr,int n,int base,int table){	
	int count[table];
	int i;
	for(i=0;i<table;i++)
	        count[i]=0;
	for(i=0;i<n;i++){
	        count[hashfun(arr[i],base,table)]++;
	}
     int col=0;
     for(i=0;i<table;i++)
     	col+=max(0,--count[i]);        
  /*   for(i=0;i<table;i++)
           printf("index = %d %d\n",i,count[i]);
    */     
     return col;
}

int isvalid(char *str){
        int i=0;
        while(str[i]!='\0')
                if(!isalpha(str[i++]))
                        return 0;
        return 1;
}

struct strbook* parser(){
        char **book;
        int size=10;
        book = (char**)
        myalloc(size*sizeof(char*));
        int i=0;
        FILE *fp = fopen("input.txt","r");
        if(!fp){
                printf("file invalid\n");
                exit(1);
        }
        char word[50];
        while(fscanf(fp,"%49[^ ] ",word)!=EOF){
                if(isvalid(word)){
                      if(i>=size){
                                book = (char**)myrealloc(book,2*size*sizeof(char*));
                                size*=2;
                      }
                      int len = strlen(word);
                      book[i]=(char*)myalloc((len+1)*sizeof(char));
                      strcpy(book[i],word);
                      i++; 
                    
                }
        }
        
        printf("total valid  strings= %d\n",i);
        book = (char**)myrealloc(book,(i)*sizeof(char*));        
      
        struct strbook *bookst;
        bookst=(struct strbook *)myalloc(sizeof(struct strbook));
        
        bookst->book = book;
        bookst->n = i;
        fclose(fp);
        return bookst;       
}

int bestval(char **arr,int n){
        int base[3]={611953,645667,642111};
        int table[3]={5000,500,50};
        int i,j;
        int val = 99999999;
        int bestb=0;
        int bestt=0;
        for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                        int x = collisioncount(arr,n,base[i],table[j]);
                        printf("for base = %d table= %d\n collsions= %d\n",base[i],table[j],x);
                        if(x<val){
                                val=x;
                                bestb=base[i];
                                bestt=table[j];
                        }
                }
        }
        return bestt;
}

Table createTable(int size){
	Table tb = (Table)myalloc(sizeof(struct table));
	tb->inscost=0;
	tb->qcost=0;
	tb->size=size;
	tb->elecount=0;
	tb->adjlist = (struct ll**)myalloc(size*sizeof(struct ll*));
	int i;
	for(i=0;i<size;i++)
		tb->adjlist[i] = createList();
	return tb;
}

Table insertAt(Table t,char **book,int j){
	int index = hashfun(book[j],611953,t->size);
	//printf("adding str- %s ,at index- %d\n",book[j],index);
	t = insertAtEnd(t,t->adjlist[index],book[j],j);
	return t;
}

int insertAll(Table t,char **book,int n){
	int i;
	for(i=0;i<n;i++)
		t = insertAt(t,book,i);
	return t->inscost;
}

Record lookup(Table t,char *str){
	int sz = t->size;
	int index = hashfun(str,611953,t->size);
	LL list = t->adjlist[index];
	Node head = list->head;
	int cost=0;
    while(head){
    	if(!strcmp(str,head->data->name)){
    		t->qcost+= cost;
    //		printf("for index-%d, string - %s, cost- %d\n",index+1,str,cost);
    		return head->data;
    	}
        head = head->next;
        ++cost;
    }
	return NULL;
}

int lookupAll(Table t,char **book,double m,int n){
	t->qcost=0;
	int sz = m*n;
	int i;
	for(i=0;i<sz;i++)
		lookup(t,book[i]);
	return t->qcost;
}

void freeTable(Table t){
	int sz = t->size;
	int i;
	for(i=0;i<sz;i++){
		freeList(t->adjlist[i]);
	}
	myfree(t->adjlist);
	myfree(t);
}

void freeBook(char **book,int n){
	int i;
	for(i=0;i<n;i++){
    	 myfree(book[i]);
    }
    myfree(book);
}

void printTable(Table t){
	int n= t->size;
	int i;
	for(i=0;i<n;i++){
		printf("\n");
		printf("for table number i = %d\n",i+1);
		Node head = t->adjlist[i]->head;
		while(head){
			printf("%s (%d) -> ",head->data->name,head->data->cnt);
			head=head->next;
		}
	}
}

int main(){
    struct strbook *st = parser();
    char** book = st->book;
    int n = st->n;
    int i=0;
   /* printf("pritning book\n");
    for(i=0;i<n;i++){
    	printf("%s\n",book[i]);
    }*/
   // int sz = bestval(book,n);
  //  printf("table size is:- %d\n",sz);
    Table t = createTable(10);
    int cost = insertAll(t,book,n);
    printTable(t);
     printf("\n****************\n");
    printf("table stats:- \n");
    printf("table size:-%d\n",t->size);
    printf("table inscost:-%d	%d\n",cost,t->inscost);
    printf("table elecount:-%d\n",t->elecount);
	printf("table lookup cost- %d\n",lookupAll(t,book,1,n));
    freeTable(t);
   	freeBook(book,n); 
    myfree(st);
    //printf("total heap:- %d\n",heap);
    //printf("total heap:- %lld\n",maxheap);
}
