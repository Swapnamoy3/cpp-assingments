/*
Create a STACK class with operation for initialization, push and pop. Support for 
checking underflow and overflow condition are also to be provided. 
*/

#include<iostream>
#define size 4
using namespace std;

class STACK {
    int arr[size];// array implementation of stack
    int currptr;//pointer to locate free element of stack
    public:

        STACK(){
            currptr=0;
        }

        void push(int n){
            if(currptr==size) {cout<<"Overflow!!!\n"; return;}
            arr[currptr++]=n;
            
        }

        int pop(){
            if(currptr==0) {cout<<"UnderFlow!!! ";return -1;}
            return arr[--currptr];
        }
};

int main(){
STACK s;
s.push(10);
s.push(20);
s.push(30);
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
s.push(60);
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;




}
