/*
Consider a class Student with roll, name and score as attributes. Support to take and display data is also there.  One wants to works with array of Student objects. May collect data for array elements, display those. In case index goes out of bounds, exception is to be raised with suitable message.
*/

#include<iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    double score;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Score: ";
        cin >> score;
    }

    void display() {
        cout << "Roll Number: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;
    }
};

class student_Array{
    Student* array;
    int max_N;
public:
    student_Array(int size){
        max_N=size;
        array = new Student[max_N];
    }

    void input(){
        for(int i=0;i<max_N;i++){
            cout<<"Enter the details of "<<i+1<<"th element\n";
            array[i].input();
            cout<<endl;
        }
    }

    void display(){
        for(int i=0;i<max_N;i++){
            cout<<"Enter the details of "<<i+1<<"th element\n";
            array[i].display();
            cout<<endl;
        }
    }

    Student& operator[] (int i){
        if(i<0 || i>=max_N) throw i;
        else{
            return array[i];
        } 
    }

};

int main(){
    
        int maxArraySize;
    
    cout << "Enter the maximum number of students: ";
    cin >> maxArraySize;

    student_Array studentArray(maxArraySize);

    studentArray.input();
    cout << "Data for all students:" << endl;
    studentArray.display();

    return 0;
}