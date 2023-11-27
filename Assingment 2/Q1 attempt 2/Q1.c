/*
1. Write a program to store student information in a file and t do the following operations. Information 
includes roll, name, and score in five subjects. Use may like to add record (ensure roll number is unique), 
display all records showing roll, name and total score. User may search for the record against a roll. User 
may edit the details a record. User may delete record. Deletion may be logical (by some means indicate it is 
an invalid record and to be avoided in processing) and physical (file will not have the record)
*/

//Name:- swapnamoy garai
//class:- UG2 CSE
//Roll No:- 002210501001

/*
- add record
- display record
- search record against roll
- edit record
- delete record

*/

#include<stdio.h>
#include<stdlib.h>

struct student{
    int roll;
    char name[31];
    int score[5];
};
typedef struct student studentRecord;

studentRecord take_input(){
    studentRecord s;
    printf("\nenter roll: ");
    scanf("%d",&s.roll);
    printf("enter name: ");
    scanf("%s",s.name);
    printf("enter 5 scores: ");
    for(int i=0;i<5;i++) scanf("%d",&s.score[i]);

    return s;
}

void print(studentRecord s){
    printf("Name: %s\n",s.name);
    printf("Roll: %d\n",s.roll);
    printf("Scores of 5 sujects: ");
    for(int i=0;i<5;i++) printf("%d ",s.score[i]);

    printf("\n\n\n");

}

void print_records(FILE* fp){
    studentRecord buffer;
    fread(&buffer,sizeof(studentRecord),1,fp);
    while(!feof(fp)){
        print(buffer);
        fread(&buffer,sizeof(studentRecord),1,fp);
    }
}

/*

*/
FILE* create_file(char name[]){
    FILE* fp= fopen(name,"wb");
    if(fp==NULL){
        printf(" %s File is not created for some unkonwn error",name);
    }

    return fp;
}

FILE* open_file(char name[],char mode[]){
    FILE* fp = fopen(name,mode);
    return fp;
}



void add_record(FILE* fp,studentRecord s){
    fwrite(&s,sizeof(studentRecord),1,fp);
}

studentRecord searchRecord(FILE* fp, int targetRoll){
    studentRecord s;
    searchRecord(fp,2);
    fread(&s,sizeof(studentRecord),1,fp);
    while(!feof(fp)){
        if(s.roll==targetRoll)
        break;
        fread(&s,sizeof(studentRecord),1,fp);

    }

    if(s.roll==targetRoll){
        printf("\nRecord found:\n");
        print(s);
    }else{
        printf("Record not find");
    }
    
    return s;
}



int main(){
    FILE* fp =create_file("student records.dat");
    studentRecord s;
    s=take_input();
    add_record(fp,s);
    fclose(fp);

    fp=open_file("student records.dat","ab");
    s=take_input();
    add_record(fp,s);
    s=take_input();
    add_record(fp,s);
    s=take_input();
    add_record(fp,s);

    fclose(fp);



    fp=open_file("student records.dat","rb");

    // searchRecord(fp,2);
    edit_record(fp,2);
    fp=open_file("student records.dat","rb");


    print_records(fp);
    fclose(fp);
}