#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createsub(FILE *fp,int k,int *files);
void mergefiles(FILE *f1,FILE *f2,int index);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(){
    int numSub = 8;
    FILE *fp = fopen("input.txt","r");
    char **filnames;
    if(!fp){
        printf("can't open file\n");
        exit(1);
    }
    int *files = (int*)malloc(sizeof(int));
    *files=0;
    createsub(fp,numSub,files);
    
    
    int totalfiles = *files;
    printf("total finels: %d\n",totalfiles);
    char filename[20];
    
    sprintf(filename,"out%d.txt",1);
    FILE *f1 = fopen(filename,"r");
    sprintf(filename,"out%d.txt",2);
    FILE *f2 = fopen(filename,"r");
    mergefiles(f1,f2,totalfiles+1);

    
    int lindx = totalfiles+1;
    int i;
    for(i=3;i<=totalfiles;i++){
        
        sprintf(filename,"out%d.txt",i);
        FILE *f1 = fopen(filename,"r");
        sprintf(filename,"out%d.txt",lindx);
        FILE *f2 = fopen(filename,"r");
        mergefiles(f1,f2,lindx+1);
        lindx++;
        
    }
    
}

void createsub(FILE *fp,int k,int *files){
    /* V.V.Imp: 
     * line number 60 have to close the file otherwise during 
     * the execution it will remain in buffer and won't be
     * written down in the output file
     */
    
    
    char out[10];
    int index=1;
    (*files)++;
    int i=0;
    int x;
    sprintf(out,"out%d.txt",index);
    FILE *f = fopen(out,"w");
    int *arr = (int*)malloc(k*sizeof(int));
    while(fscanf(fp,"%d\n",&x)==1){
        if(i>=k){
            
            mergeSort(arr,0,i-1);
            int adex;
            for(adex=0;adex<i;adex++){
                fprintf(f,"%d\n",arr[adex]);
           //     printf("printing is: %d\t",arr[adex]);
            }
         //   printf("\n************\n");
            fclose(f);
            i=0;
            sprintf(out,"out%d.txt",++index);
            //printf("index: %s\n",index);
            //printf("out string:- %s\n",out);
            f = fopen(out,"w"); 
            (*files)++;
           
        }
        arr[i]=x;
       // printf("arrays element is : %d  ",arr[i]);
        i++;
    }
    
    mergeSort(arr,0,i-1);
    int adex;
    for(adex=0;adex<i;adex++){
        fprintf(f,"%d\n",arr[adex]);
    }
        
    free(arr);
    fclose(f);
    fclose(fp);
}

void mergefiles(FILE *f1,FILE *f2,int index){
    char name[10];
    sprintf(name,"out%d.txt",index);
    FILE *f = fopen(name,"w");
    int val1,val2;
    fscanf(f1,"%d",&val1);
    fscanf(f2,"%d",&val2);
    printf("%d  %d\n",val1,val2);
    if(feof(f1))
        printf("file 1 empty\n");
    if(feof(f2))
        printf("file 2 empty\n");
    
    while(!feof(f1) && !feof(f2)){
      //  printf("///////////////\n");
        if(val1<=val2){
            fprintf(f,"%d\n",val1);
          //  printf("value: %d   ",val1);
            fscanf(f1,"%d",&val1);
        }
        else{
        //    printf("///////////////\n");
            fprintf(f,"%d\n",val2);
          //  printf("value: %d   ",val2);
            fscanf(f2,"%d",&val2);
        }
    }
    while(!feof(f1)){
        fprintf(f,"%d\n",val1);
        fscanf(f1,"%d",&val1);
    }
    
    while(!feof(f2)){
        fprintf(f,"%d\n",val2);
        fscanf(f2,"%d",&val2);
    }
    fclose(f1); fclose(f2); fclose(f);
    
    
    
}

///////////
///////////
///////////
///////////
///////////
// ************************** merge sort from gfg ***********************************

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) // r is szei-1
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
