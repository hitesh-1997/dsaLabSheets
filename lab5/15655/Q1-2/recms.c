#include <math.h>
#include <stdio.h> 
#include "def.h"
#include "merge.h"


// lo=0, high=n-1
void mergesort(Element *ls,int low,int high){
	
	if(low<high){
		//printf("low = %d high= %d\n",low,high);
		int mid = low+(high-low)/2;
		mergesort(ls,low,mid);
		mergesort(ls,mid+1,high);
		Element ls1[mid-low+1];
		Element ls2[high-mid];
		int sz1 = mid-low+1;
		int sz2 = high-mid;
		int i;
		for(i=0;i<sz1;i++){
		//printf("**************low = %d high= %d\n",low,mid);
		
			ls1[i]=ls[i+low];
		}
		for(i=0;i<sz2;i++){
			ls2[i]=ls[mid+1+i];
		}
		
		merge(ls1,sz1,ls2,sz2,ls,low,high);
		
		for(i=low;i<=high;i++){
	//	printf("name: %s	cgpa = %lf\n",ls[i].name,ls[i].cgpa);
		}
	}
}



