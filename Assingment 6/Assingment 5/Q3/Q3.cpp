/*Employee has unique emp-id, name, designation and basic pay. An employee is either a permanent one or contractual. For permanent employee salary is computed as basic pay+ 
hra (30% of basic pay) + da (80% of basic pay). For contractual employee it is basic pay + allowance (it is different for different contractual employee). An employee pointer may point to either of the two categories and accordingly the salary has to be created.
Design the classes and implement.*/

#include<iostream>
using namespace std;
class Employee {
protected:
    string email;
    string name;
    string designation;
    int basic_pay;
    int salary;
public:
    Employee(){};
    Employee(string email,string name,string designation,int basic_pay){
        this-> email = email;
        this-> name = name;
        this-> designation = designation;
        this-> basic_pay = basic_pay;
    }

    virtual void printDATA(){
        cout<<"Name: "<<name<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"Basic Pay: "<<basic_pay<<endl;
        cout<<"Salary: "<<salary<<endl<<endl;
    }
};

class Permanent_Employee:public Employee{
public:
    Permanent_Employee(string email,string name,string designation,int basic_pay):Employee( email, name, designation, basic_pay){
        salary = (1+1.1)*basic_pay;
    };
};

class Contractual_Employee:public Employee{
public:
    Contractual_Employee(string email,string name,string designation,int basic_pay,int allowance):Employee( email, name, designation, basic_pay){
        salary = basic_pay +allowance;
    };
};


int main(){
    Permanent_Employee CEO("ceo@gmail.com","ceo","CEO",1000);
    Contractual_Employee CA("ca@gmail.com","ca","CA",100,500);
    Employee* e=&CEO;
    e->printDATA();
    e=&CA;
    e->printDATA();

}