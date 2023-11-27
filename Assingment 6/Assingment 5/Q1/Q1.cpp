/*
There are number of students. For every student roll (unique), name is to be 
stored. For each subject, subject code and name is to be stored. A student can opt 
for number of subjects. System should be able to maintain student list, subject list 
and will be able to answer: 

i) which student has selected which subjects and
ii) for a subjects who are the students. 
Design the classes and implement. For list consider memory data structure. 
*/

/*
class design:- 
 student class -> when fromed stodes in a list the sujects
 sujects class -> when fromed ,from an array search the su and add the student name

 student lsit->sujects
 suject list->students
*/
#include<iostream>
using namespace std;


class student;
class suject;

class studentList{
    student** stdArray;
    int n;
public:
    friend class student;
    studentList(){
        stdArray = new student*[100];
        n=0;
    }

    void printList();
    ~studentList(){delete[] stdArray;};
};
studentList stdlist;

class sujectList{
    suject** suArray;
    int n;
public:
    friend class suject;
    sujectList(){
        suArray = new suject* [100];
        n=0;
    }

    void printList();
    ~sujectList(){delete[] suArray;};

};
sujectList sulist;


class suject{
    string name;
    int code;
    student** studentsWhoTakenThis;
    int n;
public:
    suject(string name,int code){
        this->name=name;
        this->code=code;
        sulist.suArray[sulist.n++]=this;
        this->n=0;
        studentsWhoTakenThis = new student* [100];
    }

    void info(){
        cout<<"Suject name: "<<name<<endl;
        cout<<"Suject code: "<<code<<endl;
    }

    void students();
    friend class student;
};




class student {
    string name;
    int roll;
    suject** suArray;
    int n; 
public:
    student(string name,int roll,suject** arr,int noOfSu){
        this->name=name;
        this->roll=roll;
        this->suArray=arr;
        this->n=noOfSu;
        stdlist.stdArray[stdlist.n++]=this;
        for(int i=0;i<noOfSu;i++){
            suArray[i]->studentsWhoTakenThis[suArray[i]->n++]=this;
        }
    }

    void info(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll: "<<roll<<endl;
        for(int i=0;i<n;i++){
            cout<<suArray[i]->name<<" ";
        }
    }
};


void studentList::printList(){
        for(int i=0;i<n;i++){
        stdArray[i]->info();
        cout<<endl;
        }
}

void sujectList::printList(){
        for(int i=0;i<n;i++){
            suArray[i]->info();
        }
}


void suject::students(){

        for(int i=0;i<n;i++){
            cout<<"kldf";
            studentsWhoTakenThis[i]->info();
        }
    }








int main(){
    suject maths("maths",123);
    suject english("english",458);
    suject geo("geo",789);

    suject* arr[3]={&maths,&english,&geo};
    student s1("swpa",1,arr,3);
    student s2("ahi",2,arr,3);
    s1.info();
cout<<endl<<endl;
    stdlist.printList();
cout<<endl<<endl;
    sulist.printList();
cout<<endl<<endl;
    maths.students();
}