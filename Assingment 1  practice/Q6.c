/*
Implement Q.5 using structure
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int roll;
    char name[31];
}student;

void sort(student* s,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].roll>s[j].roll){
                student t=s[i];
                s[i]=s[j];
                s[j]=t;

            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);

    student* s=(student*)malloc(sizeof(student)*n);
    for(int i=0;i<n;i++){
        scanf("%d %s",&s[i].roll,s[i].name);
    }

    sort(s,n);

        for(int i=0;i<n;i++){
        printf("%d %s\n",s[i].roll,s[i].name);
    }


}