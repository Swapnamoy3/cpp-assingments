/*
. Create an APPLICANT class with application id (auto generated as last id +1), 
name and score. Support must be there to receive applicant data, show applicant 
details and to find out number of applicants
*/
#include<iostream>
using namespace std;

class APPLICANT{
    int id;
    char name[31];
    int score;
    public:
    
    static int last_id;
    
        void inputData(){
            id=last_id+1;
            cout<<"\nenter name: ";
            cin>>name;
            cout<<"Enter score: ";
            cin>>score;
            last_id=id;
        }

        void showData(){
            cout<<"\nid: "<<id;
            cout<<" name: "<<name;
            cout<<" score: "<<score;
        }

        static void numberOfApplicans(){
            cout<<"\nThe number of applicants are: "<<last_id;
        }

};

int APPLICANT::last_id=0;


int main(){
    APPLICANT a,b,c;
    a.inputData();
    b.inputData();
    c.inputData();

    a.showData();
    b.showData();
    c.showData();
    APPLICANT::numberOfApplicans();

}