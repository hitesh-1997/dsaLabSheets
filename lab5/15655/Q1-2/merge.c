#include <math.h>
#include <stdio.h> 
#include "def.h"
#include "merge.h"

#ifndef MIN_MAX
#define MIN_MAX
double max(double x,double y){
	if(x>y)
		return x;
	else
		return y;
}

double min(double x,double y){
	if(x>y)
		return y;
	else
		return x;
}

#endif

//sz = n
void merge(Element *Ls1, int sz1, Element *Ls2, int sz2, Element *Ls,int low,int high){
	
	int i=0;
	int j=0;
	int count=low;
	
	while(i<sz1||j<sz2){
		if(i>=sz1){
			Ls[count]=Ls2[j++];
		}
		else if(j>=sz2){
			Ls[count]=Ls1[i++];
		}
		else if(Ls1[i].cgpa<Ls2[j].cgpa){
			Ls[count]=Ls1[i++];
		}
		else{
			Ls[count]=Ls2[j++];
		}
		
		count++;
	}
	
}

