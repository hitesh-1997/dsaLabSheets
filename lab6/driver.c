#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include  "mem.h"
#include "stack.h"
#include <string.h>
#include <time.h>

Record *readfile(FILE *fp,Record *arr,int *sz);
void quicksort(Record *arr,int low,int high,int);
int partition(Record *arr,int low,int high);
void swap(Record *arr,int i,int j);
void print(Record *arr,int ,int);
void insertsort(Record *arr,int low,int n);
double sortproc(Record *arr,int sz,int s);
Record *createcopy(Record *arr,int sz);
void cutoffproc(Record *copy1,Record *copy2,int sz);

int main(int argv,char **argc){
	Record *arr;
	int *init = (int*)malloc(sizeof(int));
	*init = 10;
	arr = (Record*)myalloc((*init)*sizeof(Record));
	FILE *fp = fopen("data.txt","r");
	if(!fp){
		printf("can't open this FILE\n");
		exit(1);
	}
	arr = readfile(fp,arr,init);

	printf("printing data after read file\n");

	int sz = *init;
	int i,k;
	/*for(i=0;i<sz;i++){
		printf("name is= %s and id = %lld\n",arr[i]->name,arr[i]->id);

	}*/

	

	
	FILE *f = fopen("S_time.txt","w");
	int s;
	double mintime=99999.0;
	int mins;
	for(sz=2;sz<=1000;sz++){
		
		Record *copy = createcopy(arr,sz);
		Record *copy2 = createcopy(arr,sz);
	//	print(copy,0,sz-1);

		//printf("copy array if\n");
		//print(arr,0,sz-1);
		//double time = sortproc(copy,sz,s);
		
		cutoffproc(copy,copy2,sz);

		/*
		if(time<mintime){
			mintime=time;
			mins=s;
		}
		fprintf(f, "for s value = %d time taken= %lf\n",s,time);
		//fprintf(stdout, "for s value = %d time taken= %lf\n",s,time);
		//printf("freeing the memory\n");

		*/

		//fflush(f);
		for(i=0;i<sz;i++){
			myfree(copy[i]->name);
			myfree(copy[i]);
		}
		myfree(copy);

		for(i=0;i<sz;i++){
			myfree(copy2[i]->name);
			myfree(copy2[i]);
		}
		myfree(copy2);
	
	}
	//fprintf(f, "**********************************\n");
	//fprintf(f, "mintime for qsort= %lf at S = %d\n", mintime,mins);
	//fflush(f);
	printf("after sorting the array\n");
	for(i=0;i<sz;i++){
	//	printf("name is= %s and id = %lld\n",arr[i]->name,arr[i]->id);

	}

	fclose(f);
	fclose(fp);

}

void cutoffproc(Record *copy1,Record *copy2,int sz){
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
	printf("for size = %d time diff= %lf\n",sz,(tt2-tt1));
}


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

void print(Record *arr,int lo,int hi){
	int i;
	for(i=lo;i<=hi;i++){
		printf("name is= %s and id = %lld\n",arr[i]->name,arr[i]->id);

	}
}

// ********************* file read *****************  
Record *readfile(FILE *fp,Record *arr,int *sz){
	char name[15];
	lli value;

	int i=0;
	while(fscanf(fp,"%14[^ ] %lld\n",name,&value)==2){
		//printf("data read= %s  %lld\n",name,value);

		if(i>=*sz){
			arr = (Record*)myrealloc(arr,2*(*sz)*sizeof(Record));
			(*sz)*=2;
		}

		arr[i] = (Record)myalloc(sizeof(struct rec));
		arr[i]->id = value;
		int len = strlen(name);
		arr[i]->name = (char*)myalloc((len+1)*sizeof(char));
		strcpy(arr[i]->name,name);

		i++;


	}

	arr = (Record*)myrealloc(arr,i*sizeof(Record));
	(*sz)=i;
	return arr;
}

//******** file read end *****************


// *****************qsort ******************


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







