#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("input.txt","r");
    if(fp==NULL){
        printf("unable to open the file");
        exit(1);
    }
    int ch;
    int count=0;
    
    
    while(1){
        fscanf(fp,"%d",&ch);
        
        if(ch==32)
            continue;
        count+=ch;
        if(ch=='\n')
            break;
        printf("%d\n",ch);
    }
    
//    fscanf(fp,"%s",ch);
  //  printf("%s",ch);
    printf("\ndone reading, count= %d\n",count);

    fclose(fp);
}
