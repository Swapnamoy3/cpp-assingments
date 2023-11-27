
#include<stdio.h>
#include<stdlib.h>

typedef struct  
{
    int a;
}text;
  
void print_records(FILE* fp){
    text buffer;
    fread(&buffer,sizeof(text),1,fp);
    while(!feof(fp)){
        printf("%d ",buffer.a);
        fread(&buffer,sizeof(text),1,fp);
    }
}



int main(){
    char att[3]="wb";
    FILE* fp = fopen("ac.dat",att);
    text num;
    num.a=10;
    fwrite(&num,sizeof(num),1,fp);
    fclose(fp);
     fp = fopen("ac.dat","ab");
    fwrite(&num,sizeof(num),1,fp);
    fwrite(&num,sizeof(num),1,fp);
fclose(fp);
    fp = fopen("ac.dat","rb+");
    num.a=99;
    fseek(fp,0,0);
    fflush(stdin);
    fwrite(&num,sizeof(num),1,fp);
    fclose(fp);
    fp = fopen("ac.dat","rb");


    print_records(fp);
    fclose(fp);


}