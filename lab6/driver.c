#include "def.h"
#include  "mem.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <math.h>


struct timestr{
	double ins;
	double qs;
};

Record *readfile(FILE *fp,Record *arr,int *sz,int *i);
void quicksort(Record *arr,int low,int high,int);
int partition(Record *arr,int low,int high);
void swap(Record *arr,int i,int j);
void print(Record *arr,int ,int);
void insertsort(Record *arr,int low,int n);
double sortproc(Record *arr,int sz,int s);
Record *createcopy(Record *arr,int sz);
struct timestr *testrun(Record *copy1,Record *copy2,int sz);
int estimatecutoff(Record *arr,int sz);
void freecopy(Record *,int sz);
void readforn(char*,int n,int estsz,FILE *f);

#define fact 1e-9

int main(int argv,char **argc){
	Record *arr;
	int *init = (int*)myalloc(sizeof(int));
	*init = 10;
	arr = (Record*)myalloc((*init)*sizeof(Record));
	FILE *fp = fopen(argc[1],"r");
	if(!fp){
		printf("can't open this FILE\n");
		exit(1);
	}
	int *index = (int*)myalloc(sizeof(int));
	*index=0;
	arr = readfile(fp,arr,init,index);

	printf("printing data after read file\n");

	int sz = *init;
	int i,k;
	/*for(i=0;i<sz;i++){
		printf("name is= %s and id = %lld\n",arr[i]->name,arr[i]->id);

	}*/

	int estsz = estimatecutoff(arr,sz);
	printf("estimatecutoff size is equal to : %d\n",estsz);
	freecopy(arr,sz);
	fclose(fp);
	myfree(index);
	myfree(init);

	FILE *f = fopen(argc[2],"w");
	int n = 1e3;
	for(i=n;i<1e3;i*=10){
		readforn(argc[1],i,estsz,f);
	}

	printf("current memory:- %lld\n",heap);
	printf("max memory:- %lld\n",maxheap);
}

void readforn(char *name,int n,int estsz,FILE *f){
	Record *arr;
	arr = (Record*)myalloc(n*sizeof(Record));
	int *index = (int*)myalloc(sizeof(int));
	*index = 0;
	int *s = (int*)myalloc(sizeof(int));
	*s = n;
	while(*index < n){
		FILE *fp = fopen(name,"r");
		if(!fp){
			printf("\ncants open file\n");
			exit(1);
		}
		arr = readfile(fp,arr,s,index);
		fclose(fp);
	}
	int lstsize = *index;

	double timetaken = sortproc(arr,lstsize,estsz);
	char outfile[15];
	sprintf(outfile,"outN%d",n);
	FILE *fout = fopen(outfile,"w");
	int i=0;
	for(;i<lstsize;i++){
		fprintf(fout,"%s\t%lld\n",arr[i]->name,arr[i]->id); // correctly specify %lld not %llf
	}
	fclose(fout);
	fprintf(f,"for size = %d time taken is = %lf\n",lstsize,timetaken);
	freecopy(arr,n);
	myfree(index);
	myfree(s);
}


int estimatecutoff(Record *arr,int sz){

	int min = 5;
	int max = 500;

	sz = min;
	Record *copy1 = createcopy(arr,sz);
	Record *copy2 = createcopy(arr,sz);
	struct timestr *t1 = testrun(copy1,copy2,min);
	assert((t1->ins)<(t1->qs));
	freecopy(copy1,sz);
	freecopy(copy2,sz);


	sz = max;
	copy1 = createcopy(arr,sz);
	copy2 = createcopy(arr,sz);
	struct timestr *t2 = testrun(copy1,copy2,max);
	assert((t2->qs)<(t2->ins));
	freecopy(copy1,sz);
	freecopy(copy2,sz);

	myfree(t1);
	myfree(t2);
	struct timestr *tt = (struct timestr*)myalloc(sizeof(struct timestr));

	double diff;
	do{
		//printf("for sz = %d \n",sz);
		
		sz = min + (max-min)/2;
		Record *copy1 = createcopy(arr,sz);
		Record *copy2 = createcopy(arr,sz);
		tt = testrun(copy1,copy2,sz);
		//print(copy1,0,sz);
		if((tt->ins)<(tt->qs)){
			min = sz+1;
		}
		else{
			max = sz-1;
		}
		freecopy(copy1,sz);
		freecopy(copy2,sz);
		//printf("for sz = %d time diff= %lf\n",sz,fabs(tt->qs - tt->ins));
		diff = fabs((tt->qs)-(tt->ins));
	}while(diff>fact); 

	return sz;

}

struct timestr *testrun(Record *copy1,Record *copy2,int sz){
	clock_t t,t1,t2;
	t = clock();
	//printf("value of t= %lf\n",((double)t)/CLOCKS_PER_SEC );
	quicksort(copy1,0,sz-1,1);
	t = clock()-t;
	//printf("value of t= %lf\n",((double)t)/CLOCKS_PER_SEC );
	double tt1 = ((double)t)/CLOCKS_PER_SEC;
	t = clock();
	insertsort(copy2,0,sz);
	t = clock()-t;
	//printf("value of t= %lf\n",((double)t)/CLOCKS_PER_SEC );
	double tt2 = ((double)t)/CLOCKS_PER_SEC;
	//printf("*********qsort = %lf ins sort= %lf\n",tt1,tt2);
	struct timestr *ptr = (struct timestr*)myalloc(sizeof(struct timestr));
	ptr->ins = tt2;
	ptr->qs =tt1;
	return ptr;
}

//*****************************************************************
Record *createcopy(Record *arr,int sz){
	Record *copy = (Record*)myalloc(sz*sizeof(Record));
	int i;
	for(i=0;i<sz;i++){
		copy[i] = (Record)myalloc(sizeof(struct rec));
		copy[i]->id = arr[i]->id;
		int len = strlen(arr[i]->name);
		copy[i]->name =  (char*)myalloc((len+5)*sizeof(char));
		strncpy(copy[i]->name,arr[i]->name,len);
	}
	return copy;
}

void freecopy(Record *copy,int sz){
	int i;
	for(i=0;i<sz;i++){
		myfree(copy[i]->name);
		myfree(copy[i]);
	}
	myfree(copy);

}

//***********************************************
void print(Record *arr,int lo,int hi){
	int i;
	for(i=lo;i<=hi;i++){
		printf("name is= %s and id = %lld\n",arr[i]->name,arr[i]->id);

	}
}

// ********************* file read *****************  
Record *readfile(FILE *fp,Record *arr,int *sz,int *i){
	char name[15];
	lli value;
	while(fscanf(fp,"%14[^ ] %lld\n",name,&value)==2){
		//printf("data read= %s  %lld\n",name,value);

		if((*i)>=*sz){
			arr = (Record*)myrealloc(arr,2*(*sz)*sizeof(Record));
			(*sz)*=2;
		}

		arr[*i] = (Record)myalloc(sizeof(struct rec));
		arr[*i]->id = value;
		int len = strlen(name);
		arr[*i]->name = (char*)myalloc((len+1)*sizeof(char));
		strcpy(arr[*i]->name,name);

		(*i)++;


	}

	arr = (Record*)myrealloc(arr,(*i)*sizeof(Record));
	(*sz)=(*i);
	return arr;
}

//******** file read end *****************


// *****************qsort ******************

double sortproc(Record *arr,int sz,int s){
	clock_t t;
	t = clock();
	quicksort(arr,0,sz-1,s);
	if(s>1)
		insertsort(arr,0,sz);
	t = clock()-t;
	double timetaken = ((double)t)/CLOCKS_PER_SEC;
	return timetaken;
}


void swap(Record *arr,int i,int j){
	Record temp;
	temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition(Record *arr,int low,int high){
	int pivot = low+rand()%(high-low+1);
	swap(arr,pivot,high);
	lli cmp = arr[high]->id; 
    int i = (low - 1);  
 	int j;
    for (j = low; j <= high- 1; j++){   
    	lli jval = arr[j]->id;
    	if (jval <= cmp){
            i++;   
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,j);
    return (i + 1);
}


void quicksort(Record *arr,int low,int high,int s){  // high = n-1
	LL stack = create();
	if(high-low+1 > s)
		push(stack,low,high);
	while(!isempty(stack)){
		Node value = top(stack);
		pop(stack);
		int p = partition(arr,value->first,value->last);
		int first = value->first;
		int second = value->last;
		if(p-first > s){
			push(stack,first,p-1);
		}
		if(second-p > s){
			push(stack,p+1,second);
		}
	}
}

void insertsort(Record *arr,int low,int n){ // high = n
	int i, j;
   for (i = 1; i < n; i++){
       lli key = arr[i]->id;
       Record temp = arr[i];
       j = i-1;
       while (j >= 0 && arr[j]->id > key){
           arr[j+1]=arr[j];
           j = j-1;
       }
       arr[j+1] = temp;
   }
}







