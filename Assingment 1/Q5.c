#include<stdio.h>
#include<stdlib.h>

int* createIntArray(int n){
    int* p=(int *)malloc(sizeof(int)*n);
    return p;
}

void sort(int *p,char**char_p,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]>p[j]){
                int temp=p[i];
                p[i]=p[j];
                p[j]=temp;

                char* c_p=char_p[i];
                char_p[i]=char_p[j];
                char_p[j]=c_p;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int*p=createIntArray(n);
    for(int i=0;i<n;i++){
        scanf("%d",p+i);
    }

    char** char_p;
    char_p=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        char_p[i]=(char*)malloc(sizeof(char)*31);
        scanf("%s",char_p[i]);
    }
    
    sort(p,char_p,n);

    for(int i=0;i<n;i++){
        printf("%d %s\n", p[i],char_p[i]);
    }



    
}