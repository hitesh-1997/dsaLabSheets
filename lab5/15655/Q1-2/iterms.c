#include <math.h>
#include <stdio.h> 
#include "def.h"
#include "merge.h"



void mergesort(Element *ls,int low,int high){
	printf("this is itermergesort *****************\n");
	int j;
	int n=high-low+1;
	int sz;
	for(sz=1;sz<n;sz*=2){
		
		for(j=0;j<n-sz;j+=2*sz){
			int low = j;
			int mid = j+sz-1;
			int high = min(n-1,j+2*sz-1);
			int sz1 = sz;
			int sz2 = high-mid;
			Element ls1[sz1];
			Element ls2[sz2];
			int i;
			for(i=0;i<sz1;i++){
				ls1[i]=ls[i+low];
			}
			for(i=0;i<sz2;i++){
				ls2[i]=ls[mid+1+i];
			}
			
			merge(ls1,sz1,ls2,sz2,ls,low,high);
		
		}
	}

}

