/*
Design a COMPLEX class, which will behave like normal integer with respect to 
- addition, 
- subtraction, 
- accepting the value and 
- Displaying the value. 
*/
#include<iostream>
using namespace std;


class COMPLEX{
    int real;
    int imaginary;
    public:
    COMPLEX(int r=0,int img=0){
        real=r;
        imaginary=img;
    }

    
    COMPLEX operator+(COMPLEX& b){
        COMPLEX res;
        res.real=real+b.real;
        res.imaginary=imaginary+b.imaginary;
        return res;
    }

    COMPLEX operator-(COMPLEX& b){
        COMPLEX res;
        res.real=real-b.real;
        res.real=real-b.real;
        return res;
    }

    void display(){
        cout<<real<<" + "<<imaginary<<"i";
    }

    void takeVlaue(){
        cout<<"Enter the new real value: ";
        cin>>real;
        cout<<"Enter the new imaginary value: ";
        cin>>imaginary;
        cout<<endl;
    }


};


int main(){
    COMPLEX c1,c2;
    c1.takeVlaue();
    c2.takeVlaue();

    COMPLEX c3=c1+c2;

    c3.display();
}