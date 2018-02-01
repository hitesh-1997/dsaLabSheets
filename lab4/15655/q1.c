#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct rec{
	char cardno[20];
	char bankcode[10];
	char expdate[10];
	char fname[20];
	char lastname[20];
};

typedef struct rec *Record;

void *readFile(FILE *fp,Record arr,int sz);
void insertInOrder(Record arr,int n,struct rec x,int* add);
void swap(Record arr,int i,int j);
void insertionSort(Record arr,int n,int* add);

unsigned long long int stack=0;

int main(int argv,char **argc){
	int sz=50;
	Record arr = (Record)malloc(sz*sizeof(struct rec));
   // printf("%d\n",atoi(argc[1]));
	FILE *fp = fopen("1000.txt","r");
	if(!fp){
		printf("\ncants open file\n");
		exit(1);
	}
	void *ptr = readFile(fp,arr,sz);
	int *sizeptr = (int *)ptr;
	sizeptr--;
	sz = *sizeptr;
	arr = (Record)ptr;
	printf("struct is:size %d\n",sz);
	int i=0;	
	/*for(i=0;i<sz;i++){
		printf("f,l = %s	%s\n",arr[i].cardno,arr[i].lastname);	
	}*/
	int* add=&i;
	insertionSort(arr,sz-1,add);
	printf("aftre sort:\n");
	for(i=0;i<sz-1;i++){
		//printf("f,l = %s	%s\n",arr[i].cardno,arr[i].lastname);
		if(atoll(arr[i+1].cardno)<atoll(arr[i].cardno)){
			printf("not sorted\n");
			break;		
		}	
	}
	printf("stack size used: %llu\n",stack);
}

void *readFile(FILE *fp,Record arr,int sz){
	char line[200];
	int i=0;
	char delim[2];
	delim[0]=',';
	delim[1]='\0';
	while(fgets(line,200,fp)!=NULL){
		if(i>=sz){
			arr = (Record)realloc(arr,2*sz*sizeof(struct rec));
			sz*=2;	
		}
		line[0]=',';
		int size = strlen(line);
		line[size-2]=',';
		//printf("line is: %s\n",line);	
		strcpy(arr[i].cardno,strtok(line,delim));
		strcpy(arr[i].bankcode,strtok(NULL,delim));
		strcpy(arr[i].expdate,strtok(NULL,delim));
		strcpy(arr[i].fname,strtok(NULL,delim));
		strcpy(arr[i].lastname,strtok(NULL,delim));
		i++;
	}
	void *s = (void *)arr;
	int *sptr = (int *)s;
	sptr--;
	*sptr = i;
	return arr;
}

void swap(Record arr,int i,int j){
	struct rec temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;	
}

void insertionSort(Record arr,int n,int* add){
	if(n==0){
		if(abs(add-&n)>stack)
			stack = (add-&n);
		return;
	}
	insertionSort(arr,n-1,add);
	insertInOrder(arr,n-1,arr[n],add);
}

void insertInOrder(Record arr,int n,struct rec x,int* add){
	// n point up to which array is sorted
	if(n==-1 || atoll(arr[n].cardno)<atoll(x.cardno)){
		if(abs(add-&n)>stack)
			stack = (add-&n);
		arr[n+1]=x;
		return;	
	}
	else{
		arr[n+1]=arr[n];
		insertInOrder(arr,n-1,x,add);	
	}
}























