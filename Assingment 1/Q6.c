#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[31];
    int age;
}person;

int sort(person* p,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].age>=p[j].age){
                person temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

int main(){
    person* p;
    int n;
    scanf("%d",&n);
    p=(person*)malloc(sizeof(person)*n);

    for(int i=0;i<n;i++){
        scanf("%s %d",p[i].name,&p[i].age);
    }

    sort(p,n);

    for(int i=0;i<n;i++){
        printf("%s %d\n",p[i].name,p[i].age);
    }


    
    
}