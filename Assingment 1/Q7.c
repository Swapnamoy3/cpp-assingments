#include<stdio.h>
#include<stdlib.h>

struct student{
    int roll;
    char name[31];
    int score;
};
typedef struct student student;

struct node{
    student s;
   struct node* next;
};
typedef struct node node;


void addNode(node** h,student data){
    node* newS=(node*)malloc(sizeof(node));
   
    if(*h==NULL){ 
    *h=newS;
    newS->s=data;
    newS->next=NULL;
    return;
    }
    node* head=*h;
    
    while(head->next!=NULL)
    head=head->next;

    head->next=newS;
    newS->next=NULL;
    newS->s=data;

    
}


void delete(node** h,student key){
   node* head=*h;

   if(head->s.roll==key.roll){
   *h=head->next;
   free(head);return;
   }
    
    while(head->next->s.roll!=key.roll){
    head=head->next;}

    head->next=head->next->next;

;

    
}

void display(node*head){
    if(head==NULL)
    return;

    while(head!=NULL){
        printf("%s %d %d\n",head->s.name,head->s.roll,head->s.score);
        head=head->next;
    }
}

int main(){
node*head=NULL;

student s;
s.score=99;
s.roll=1;
scanf("%s",s.name);
addNode(&head,s);
addNode(&head,s);
addNode(&head,s);
addNode(&head,s);

delete(&head,s);

display(head);




;}