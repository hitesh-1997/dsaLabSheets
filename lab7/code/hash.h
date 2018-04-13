#ifndef HASH_H
#define HASH_H

///////////////////////////////////
struct record{
	char *name;
	int index;
	int cnt;
};

typedef struct record *Record;

struct node{
    struct record* data;
    struct node *next;
};

struct ll{
    struct node *head;
    int size;
};

typedef struct node* Node;
typedef struct ll* LL;
//////////////////////////////
struct table{
	int size;
	int elecount;
	int inscost;
	int qcost;
	struct ll **adjlist;
};

typedef struct table *Table;

struct strbook{
        char **book;
        int n;
};
////////////////////////////////////

LL createList();
Table insertAtEnd(Table t,LL st,char *str,int index);
void freeList(LL list);

///////////////////////////////////////////////


void printTable(Table t);
int max(int x,int y);
int hashfun(char *str,int base,int table);
int collisioncount(char **arr,int n,int base,int table);
int isvalid(char *str);
struct strbook* parser();
int bestval(char **arr,int n);
Table createTable(int size);
Table insertAt(Table t,char **book,int j);
int insertAll(Table t,char **book,int n);
Record lookup(Table t,char *str);
int lookupAll(Table t,char **book,double m,int n);
void freeTable(Table t);
void freeBook(char **book,int n);

#endif
