#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM 0x7fffffff

int hashfun(char *str,int table){
	int i,sum=0;
	int len = strlen(str);
	for(i=0;i<len;i++)
		sum+=(31*sum+str[i])%table;
	return (sum&MAXIMUM)%table; 	
}

Hashtable createTable(int size){
	Hashtable table = (Hashtable)malloc(sizeof(struct hashtable));
	table->size = size;
	table->list = (struct record**)malloc(size*sizeof(struct record*));
	int i;
	for(i=0;i<size;i++){
		table->list[i] = NULL;
		
	}
	return table;
}

Record createRec(char *key,int value){
	Record rec = (Record)malloc(sizeof(struct record));
	rec->key = (char*)malloc((strlen(key)+1)*sizeof(char));
	rec->value = value;
	strcpy(rec->key,key);
	return rec;
}

int insertRec(Hashtable t,char *key,int value){
	int index = hashfun(key,t->size);
	//printf("hash index = %d\n",index);
	int i;
	for(i=index;t->list[i]!=NULL;i=(i+1)%(t->size)){
		//printf("inc****\n");
		if(!strcmp(key,t->list[i]->key))
			return -1;
	}
//	printf("hash *********index = %d\n",i);
	
	t->list[i] = createRec(key,value);
	return i;
}

int findKey(Hashtable t,char *key){
	int index = hashfun(key,t->size);
	int i=index;
//	printf("index is === %d\n",index);
	while(t->list[i]){
		if(!strcmp(key,t->list[i]->key))
			return t->list[i]->value;
		i=(i+1)%(t->size);		
	}
	return -1;
}
