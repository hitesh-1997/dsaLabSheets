#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "mem.h"


int main(){
    
	ull mb=1048576;
	int *arr = (int*)myalloc(mb);
	while(arr){
		mb*=2;
		arr = (int*)myalloc(mb);
		if(!arr)
			break;
		printf("allocated size in mb- %llu\n",(totalHeap/1048576));
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



