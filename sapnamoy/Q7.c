/*Mantain a list to store roll,name and score of student.
-->As and when required  student record may stored and deleted 
-->.also the list has to be displayed.
-->.Design sutible functions for different operations*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int roll;
    char name[31];
    int score;
}student;


typedef struct 
{
    student s;
    node* next;
}node;

void addNode(node** head){
    node* t_ptr=*head;

    node* p=(node*)malloc(sizeof(node));
    printf("enter roll, name, score of person");
    scanf("%d %s %d",&(p->s.roll),(p->s.name),(p->s.score));
    
    p->next=NULL;

    if(*head==NULL){
        head=p;
        return;
    }
    
    while(t_ptr->next!=NULL){
        t_ptr=t_ptr->next;
    }

    t_ptr->next=p;

}

void deleteNode(node* head,int roll_key){
    if(head==NULL)
    return;

    while (!(head->next->s.roll==roll_key))
    {
        head=head->next;
    }

    
    
}


int main(){
    node* head=NULL;
}