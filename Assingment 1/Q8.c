#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int roll;
    int score;
    char name[31];
}student;


void takeInput(student s[]){
    for(int i=0;i<10;i++){
        scanf("%d %d %s",&s[i].roll,&s[i].score,s[i].name);
    }
}

void sort(student s[],int n,int (*compare)(student ,student )){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            if(compare(s[i],s[j])){
            student temp=s[i];
            s[i]=s[j];
            s[j]=temp;}
        }
    }
}

int comp(student a,student b){
    return a.score>b.score;
}

void display(student s[],int n){
    for( int i=0;i<n;i++){
        printf(" %d %d %s\n",s[i].roll,s->score,s[i].name);
    }
}

int main(){

student students[3];
takeInput(students);
sort(students,3,comp);
display(students,3);


}