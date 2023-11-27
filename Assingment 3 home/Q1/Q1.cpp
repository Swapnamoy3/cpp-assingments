/*
. Write a function swap (a, b) to interchange the values of two variables. Do not 
use pointers. 

*/


void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}


#include<iostream>
using namespace std;


int main(){
    int a,b;
    cout<<"Enter values of a and b: ";
    cin>>a>>b;

    swap(a,b);

    cout<<"swaped values of a and b: ";
    cout<<a<<" "<<b;
}