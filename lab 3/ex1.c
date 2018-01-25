#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
int bits=0;
int b=5;
void p(int);
void g();
void h();
void d();


int main(){
	p(0);
	printf("add of bits= %llu\n",&bits);
	printf("add of bits= %llu\n",&b);
	int *ptr;
	ptr = (int*)malloc(sizeof(int));
	*ptr = 5;
	printf("dynamic add= %llu\n",ptr);
	
}

void p(int pilani){
	if(pilani==10)
		return;
	////int pilani=1;
	int pr=564;
	//int pilani=45;
	printf("add of p= %llu\n",&pr);
	
	printf("add of pilani= %llu\n",&pilani);
	//g();
	p(pilani+1);
}

void g(){
	int goa=2;
	printf("add of goa= %llu\n",&goa);	

	h();
}

void h(){
	int hyd=3;
	printf("add of hyd= %llu\n",&hyd);
	d();
}

void d(){
	int dub=4;
	printf("add of dub= %llu\n",&dub);
}
 
