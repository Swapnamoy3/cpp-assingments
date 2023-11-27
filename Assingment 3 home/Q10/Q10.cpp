/*
Design a STUDENT class to store roll, name, course, admission date and marks in 
5 subjects. Provide methods corresponding to admission (marks are not available 
then), receiving marks and preparing mark sheet. Support must be there to show 
the number of students who have taken admission. 
*/
#include<iostream>
using namespace std;

class STUDENT{
    int roll;
    char name[21];
    char course[20];
    int admission_date;
    int marks[5];
    public:
        static int last_roll;

        void admission(){
            roll=last_roll+1;
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Enter the course you want to be in: ";
            cin>>course;
            cout<<"Enter date: ";
            cin>>admission_date;
        }

        void prepareMarksSheet(){
            cout<<"Enter the marks of "<<name<<" have got in 5 subjects: ";
            for(int i=0;i<5;i++) cin>>marks[i];
        }

        void displayMarks(){
            for(int i=0;i<5;i++) cout<<"subject"<<i+1<<": "<<marks[i]; 
        }

        void admissionDeatais(){
            cout<<"roll: "<<roll;
            cout<<"\nName: "<<name;
            cout<<"\ncourse: "<<course;
            cout<<"\nadmission date: "<<admission_date;
        }

        static void numberOfStudents(){
            cout<<"\nNumber of admission: "<<last_roll;
        }

};

int STUDENT::last_roll=0;


int main(){
    STUDENT a,b;
    a.admission();
    b.admission();
    a.prepareMarksSheet();
    a.admissionDeatais();
    STUDENT::numberOfStudents();
    
}

