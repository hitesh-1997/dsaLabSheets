#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>



int main(){
    
	ull mb=1048576;
    double div = 1024*1048576.0;
	int *arr = (int*)myalloc(mb);
	while(arr){
		mb*=2;
		//mb = rand()%15000+10000;
        arr = (int*)myalloc(mb);
		if(!arr)
			break;
        
		printf("allocated size in gb- %lf\n",maxheap/div);
		myfree(arr);
	}
	printf("loop finished\n");
    
	/*
	
	printf("initial heap size= %zu\n",totalHeap);
	
	int x,i;
	for(i=1;i<=10;i++){
		x = abs((i*i*i+8*i*(i/5)-9*i));
		printf("for loop i= %d, m is= %d\n",i,x);
		//Mem m = myalloc(x*sizeof(int));
		int *arr = (int*)myalloc(x*4);
		printf("first and last add= %llu and %llu\n",&arr[0],&arr[x-1]);
		printf("total size= %zu\n",totalHeap);
		myfree(arr);
		//printf("total heap size after free= %zu\n",totalHeap);
	}

	*/

}



