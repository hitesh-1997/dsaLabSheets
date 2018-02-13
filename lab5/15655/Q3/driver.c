#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createsub(FILE *fp,int k);
void mergefiles(FILE *f1,FILE *f2);

int main(){
    int numSub = 3;
    FILE *fp = fopen("input.txt","r");
    if(!fp){
        printf("can't open file\n");
        exit(1);
    }
  //  createsub(fp,numSub);
    FILE *f1 = fopen("out0.txt","r");
    FILE *f2 = fopen("out1.txt","r");
    mergefiles(f1,f2);
}

void createsub(FILE *fp,int k){
    char out[10]="out0.txt";
    char index[10]="1";
    int i=0;
    int x;
    FILE *f = fopen(out,"w");
    while(fscanf(fp,"%d\n",&x)!=EOF){
        if(i>=k){
            i=0;
            strcpy(out,"out");
            int value = atoi(index);
            strcat(out,index);
            strcat(out,".txt");
            sprintf(index,"%d",value+1);
            //printf("index: %s\n",index);
            //printf("out string:- %s\n",out);
            f = fopen(out,"w"); 
           
        }
         fprintf(f,"%d\n",x);
         i++;
    }
}

void mergefiles(FILE *f1,FILE *f2){
    
    FILE *f = fopen("mergeout.txt","w");
    int val1,val2;
    fscanf(f1,"%d\n",&val1);
    fscanf(f2,"%d\n",&val2);
    int fval;
    while(!feof(f1) && !feof(f2)){
        if(val1<=val2){
            fprintf(f,"%d\n",val1);
            fscanf(f1,"%d\n",&val1);
        }
        else{
            fprintf(f,"%d\n",val2);
            fscanf(f2,"%d\n",&val2);
        }
    }
    while(!feof(f1)){
        fprintf(f,"%d\n",val1);
        fscanf(f1,"%d\n",&val1);
        fval=1;
    }
    
    while(!feof(f2)){
        fprintf(f,"%d\n",val2);
        fscanf(f2,"%d\n",&val2);
        fval=2;
    }
    if(fval==1){
        fprintf(f,"%d\n",val1);
    }
    else{
        fprintf(f,"%d\n",val2);
    }
}