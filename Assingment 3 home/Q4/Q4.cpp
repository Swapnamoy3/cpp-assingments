/*
Write a function void f(int) that prints “inside f(int)”. Call the function with 
actual argument of type: i) int, ii) char, iii) float and iv) double. Add one more 
function f(float) that prints “inside f(float)”. Repeat the calls again and observe 
the outcomes. 

*/

#include<iostream>
using namespace std;

void func(int a){
    cout<<"inside f(int)"<<endl;
}

void func(float f){
    cout<<"inside f(float)";
}

int main(){
    int i=1;
    char c='1';
    float f=2.0;
    double d=2.22;
    
    func(i);
    func(c);
    func(f);
    // func(d);
}


/*//!Conclusion:- 
//# due to standared converison which favours both float and int likely we get :-
//!"error: call of overloaded 'func(double&)' is ambiguous" ERROR

*/