/*. Write a program to store student information in a file and then do the following
operations. Information includes roll, name, and score in five subjects. Use may like to
 add record (ensure roll number is unique), display all records showing roll, name and
  total score. User may search for the record against a roll. User may edit the details
   a record. User may delete record. Deletion may be logical (by some means indicate it
    is an invalid record and to be avoided in processing) and physical (file will not
    have the record).*/


/*
- add record
- display record
- search record against roll
- edit record
- delete record
    

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int roll;
    char name[31];
    int score[5];
}student;


void addRecord(){
    FILE* fp=fopen("studentRRecords.dat","ab");
    if(fp==NULL) return;

    student s;
    printf("enter roll: ");
    scanf("%d",&s.roll);
    printf("enter name: ");
    scanf("%s",s.name);
    printf("enter scores: ");
    for(int i=0;i<5;i++) scanf("%d",&s.score[i]);

    fwrite(&s,sizeof(student),1,fp);

    fclose(fp);


}

void searchRecord(){
    FILE* fp=fopen("studentRRecords.dat","rb");
    if(fp==NULL) {
        printf("error");
        return;}

    int roll;
    printf("enter the roll you want to search: ");
    scanf("%d",&roll);

    student s;
    while (fread(&s,sizeof(student),1,fp)){
        if(s.roll==roll) {
            printf("data exist\n");
            printf("roll : %d student name: %s and he Scored: ",s.roll,s.name);
            for(int i=0;i<5;i++) printf("%d ",s.score[i]);
            return;
        }
    }

    if(!feof(fp)){
        printf("data/ record do not exist");
        return;
    }

    {
        /* code */
    }
    
    
}

void displayRecord(){
    FILE* fp=fopen("studentRRecords.dat","rb");
    if(fp==NULL) {
        printf("error");
        return;}

    student s;
        
    printf("\nroll name and scors of student:- ");
    fread(&s,sizeof(student),1,fp);
    while (!feof(fp)){
        if(s.roll<0) continue;
        printf("\nRoll: %d  Name:%s\nscores : ",s.roll,s.name);
        for(int i=0;i<5;i++) printf("%d ",s.score[i]);

        fread(&s,sizeof(student),1,fp);
    
    }
    fclose(fp);

}

void editRecord(){
    int roll;
    printf("Enter roll that you want to edit: ");
    scanf("%d",&roll);

    FILE* fp=fopen("studentRRecords.dat","rb+");

    student s;
    while(fread(&s,sizeof(student),1,fp))
    if(s.roll==roll){
        fseek(fp,-1*sizeof(student),1);
        break;}

    if(feof(fp)){ printf("Record do'nt exist"); return; }

    printf("write new name and scores :");
    scanf("%s",s.name);
    for(int i=0;i<5;i++) scanf("%d",&s.score[i]);


    fwrite(&s,sizeof(student),1,fp);
    fclose(fp);


    
}

void deleteLoical(){
    int roll;
    printf("Enter roll that you want to delete: ");
    scanf("%d",&roll);
    FILE* fp=fopen("studentRRecords.dat","rb+");

    student s;
    while (fread(&s,sizeof(student),1,fp))
    {
        if(s.roll==roll){
        fseek(fp,-1*sizeof(student),1);
        break;}
    }

    if(feof(fp)){printf("Data do not exist"); return;}
    // student s1;
    s.roll=-1*roll;
    fwrite(&s,sizeof(student),1,fp);

    fclose(fp);
    

}

void deletePhysical(){
    int roll;
    printf("enter the roll that you want to delete: ");
    scanf("%d",&roll);

    FILE* fp=fopen("studentRRecords.dat","rb");
    FILE* tempP=fopen("temp.dat","wb");

    student s;

    while (fread(&s,sizeof(student),1,fp))
    {   
        if(s.roll!=roll)
        fwrite(&s,sizeof(student),1,tempP);
    }
    fclose(fp);
    fclose(tempP);

    fp=fopen("studentRRecords.dat","wb");
    tempP=fopen("temp.dat","rb");

    while (fread(&s,sizeof(student),1,tempP))
    {
        fwrite(&s,sizeof(student),1,fp);
    }

    fclose(fp);
    fclose(tempP);
    remove("temp.dat");
    
    
}

int main(){
    fclose(fopen("studentRRecords.dat","wb"));

addRecord();
addRecord();

printf("ok");
displayRecord();
// searchRecord();
deleteLoical();
displayRecord();
}