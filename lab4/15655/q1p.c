#include <stdio.h>
#include "q1p.h"
#include <stdlib.h>
#include <time.h>

int totalmem;

void* myalloc(int memory)
{
 void* a=(void*)malloc(memory+4);
 int* b1=a;
 b1[memory]=memory;
 totalmem+=(memory);
 return a;
}
void myfree(void* a)
{

int* b1=a-4;
totalmem-=b1[0];
 free(b1);

}

void attralloc(array arr,int i)
{
   // printf("***************************\n");
    arr=(array)realloc(arr,10*(i+1)*sizeof(E));printf("ik\n");
    
    //printf("***************************\n");
    int j=i;
    for(j=i+1;j<10*(i+1);j++)
                                {   printf("ik1\n");
                                    arr[j].cardno=(char*)myalloc(17*sizeof(char));printf("ik2");
                                    arr[j].bankcode=(char*)myalloc(6*sizeof(char));printf("ik3");
                                    arr[j].expdate=(char*)myalloc(8*sizeof(char));printf("ik4");
                                    arr[j].fname=(char*)myalloc(6*sizeof(char));printf("ik5");
                                    arr[j].lname=(char*)myalloc(6*sizeof(char));printf("ik6\n");
                                }
    printf("ik7\n");
}


void main()
{
    printf("k\n");
    array arr=(array)myalloc(sizeof(E));
    arr->cardno=(char*)myalloc(17*sizeof(char));
	arr->bankcode=(char*)myalloc(6*sizeof(char));
	arr->expdate=(char*)myalloc(8*sizeof(char));
	arr->fname=(char*)myalloc(6*sizeof(char));
	arr->lname=(char*)myalloc(6*sizeof(char));
    printf("k1\n");
    FILE *f=fopen("100.txt","r");
    printf("k2\n");
    if(f==NULL) printf("error\n");
    int i=0;
    clock_t t;
    t = clock();


	while(fscanf(f,"%[^,],%[^,],%[^,],%[^,],%s",arr[i].cardno,arr[i].bankcode,arr[i].expdate,arr[i].fname,arr[i].lname)!=EOF)
    {   if(i==0 || i==9|| i==99 || i==999 || i==9999) attralloc(arr,i);
        printf("%s   %s  %s   %s   %s   \n",(arr[i].cardno),(arr[i].bankcode),(arr[i].expdate),(arr[i].fname),(arr[i].lname));
        printf("%d",i);
        i++;
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("n:%d  time:%d",i+1,time_taken);
	printf("k3\n");
	fclose(f);
}


