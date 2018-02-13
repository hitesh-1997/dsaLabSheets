#include <stdio.h>
#include <stdlib.h>

int main(int argv,char **argc){
    int number = atoi(argc[1]);
    FILE *fp = fopen("input.txt","w");
    int i;
    for(i=0;i<number;i++){
        int x = rand()%20;
        fprintf(fp,"%d\n",x);
    }
    return 0;
}
