/*
Define a structure student with roll and score as attributes and with two member 
functions to take input and to show the data. Use the member functions to take 
data for a structure variable and to show. Write global function i) to modify score 
and ii) to show the data again. 
*/

#include<iostream>
using namespace std;
typedef struct 
{
    int roll;
    int score;

    void takeInput(){
        cout<<"Enter the roll and score\n";
        cin>>roll>>score;
    }

    void showData(){
        cout<<"Roll: "<<roll<<endl;
        cout<<"Score: "<<score<<endl;
    }
}student;





void modifyData(student &s){
    cout<<"Enter the roll and score\n";
    cin>>s.roll>>s.score;
}

void showData(student &s){
    cout<<"Roll: "<<s.roll<<endl;
    cout<<"Score: "<<s.score<<endl;
}



int main(){

    student s1;
    s1.takeInput();
    s1.showData();

    cout<<"Now to modify the data using gloal functions: \n";
    modifyData(s1);
    showData(s1);

}