/*
6.store name and age of number of person(provided at run time) and using dynamic allocation.
-->Collect data and display data in the ascending order of age.
-->implement  using structure
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct //defining a structure to store name and roll
{
    char name[31];
    int age;

}person;

person * createArrayOfPerson(int n){//creating array of persons using malloc 
    person * p=(person*)malloc(sizeof(person)*n);
    return p;
}


void sort_by_age(person* p,int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].age>p[j].age){//sorting by age
                person temp_person=p[i];//copying cotents of ith person
                p[i]=p[j];
                p[j]=temp_person;
            }
        }
    }
    
}

int main(){
    int n;
    scanf("%d",&n);

    person * p=createArrayOfPerson(n);

    for(int i=0;i<n;i++){
        scanf("%d %s",&p[i].age,p[i].name);
    }

    sort_by_age(p,n);

    for(int i=0;i<n;i++){
        printf("%d %s\n",p[i].age,p[i].name);
    }

    


}