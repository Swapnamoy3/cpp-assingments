/*
1. Write a program to store student information in a file and t do the following operations. Information 
includes roll, name, and score in five subjects. Use may like to add record (ensure roll number is unique), 
display all records showing roll, name and total score. User may search for the record against a roll. User 
may edit the details a record. User may delete record. Deletion may be logical (by some means indicate it is 
an invalid record and to be avoided in processing) and physical (file will not have the record). 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int roll;
    char name[31];
    int scores[5];
}student;


void SearchRecord(){
    int rollKey;
    printf("Enter the roll to search: ");
    scanf("%d",&rollKey);

    FILE* fp=fopen("StudentRecords.dat","rb");
    if(fp==NULL) {printf("Error opening the file"); return;}

    student buffer;
    while (fread(&buffer,sizeof(student),1,fp))
    {
        if(buffer.roll==rollKey) break;
    }

    if(feof(fp)) {
        printf("End of the file");
        fclose(fp);
        return;
    }

    printf("roll: %d , Name: %s he got: ",buffer.roll,buffer.name);
    for(int i=0;i<5;i++) printf("%d ",buffer.scores[i]);
    printf("\n");
    fclose(fp);
    return;
    
}

void addRecord(){
    student s;
    printf("Enter the roll: ");
    scanf("%d",&s.roll);

    printf("Enter the name: ");
    scanf("%s",s.name);

    printf("ENter the scores: ");
    for(int i=0;i<5;i++) scanf("%d",&s.scores[i]);


    FILE* fp=fopen("StudentRecords.dat","ab");
    if(fp==NULL) {printf("Error opening the file"); return;}

    fwrite(&s,sizeof(student),1,fp);

    fclose(fp);

}

void displayRecord(){
    FILE* fp=fopen("StudentRecords.dat","rb");
    if(fp==NULL) {printf("Error opening the file"); return;}

    student buffer;
    printf("\n");
    while (fread(&buffer,sizeof(student),1,fp))
    {
        if(buffer.roll<0) continue;

        printf("--> roll: %d , Name: %s he got: ",buffer.roll,buffer.name);
        for(int i=0;i<5;i++) printf("%d ",buffer.scores[i]);
        printf("\n");
    }

    fclose(fp);
    
}

void editRecord(){
    FILE* fp=fopen("StudentRecords.dat","rb+");
    if(fp==NULL) {printf("Error opening the file"); return;}

    int rollKey;
    printf("Enter the roll to edit: ");
    scanf("%d",&rollKey);

    student buffer;
    while (fread(&buffer,sizeof(student),1,fp))
    {
        if(buffer.roll==rollKey){ fseek(fp,-1*sizeof(student),1); break;}
    }

    if(feof(fp)){printf("no such result exists"); return;}

    student s;
    s.roll=rollKey;
    printf("Enter the new name: ");
    scanf("%s",s.name);

    printf("ENter the new scores: ");
    for(int i=0;i<5;i++) scanf("%d",&s.scores[i]);

    fwrite(&s,sizeof(student),1,fp);

    fclose(fp);

}

void deleteLogical(){
    int rollKey;
    printf("Enter the roll to deleete logical: ");
    scanf("%d",&rollKey);

    FILE* fp=fopen("StudentRecords.dat","rb+");
    if(fp==NULL) {printf("Error opening the file"); return;}

    student buffer;
    while (fread(&buffer,sizeof(student),1,fp))
    {
        if(buffer.roll==rollKey){ fseek(fp,-1*sizeof(student),1); break;}
    }

    if(feof(fp)){printf("no such result exists"); return;}

    buffer.roll*=-1;

    fwrite(&buffer,sizeof(student),1,fp);

    fclose(fp);
}

void deletePhysical(){
    int rollKey;
    printf("Enter the roll to delete: ");
    scanf("%d",&rollKey);

    FILE* fp1=fopen("StudentRecords.dat","rb");
    if(fp1==NULL) {printf("Error opening the file"); return;}
    
    FILE* fp2=fopen("temporary.dat","wb");
    if(fp2==NULL) {printf("Error opening the file"); return;}

    student buffer;
    while (fread(&buffer,sizeof(student),1,fp1))
    {
        if(buffer.roll==rollKey) continue;

        fwrite(&buffer,sizeof(student),1,fp2);
    }

    fclose(fp1);
    fclose(fp2);


    fp1=fopen("StudentRecords.dat","wb");
    fp2=fopen("temporary.dat","rb");

    while (fread(&buffer,sizeof(student),1,fp2))
    {
        fwrite(&buffer,sizeof(student),1,fp1);
    }

    fclose(fp1);
    fclose(fp2);

    remove("temporary.dat");
    



    


    
}

int main(){

// addRecord();
// addRecord();
// addRecord();
SearchRecord();
editRecord();
deleteLogical();
deletePhysical();
displayRecord();

}