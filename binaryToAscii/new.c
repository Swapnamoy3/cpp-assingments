#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* fp=fopen("Assingment_3_oops.pdf","rb");
    
    char c;
    while(fread(&c,sizeof(char),1,fp)){
        printf(" %d ",(int)c);
    }

}