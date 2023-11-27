/*
. Define functions f(int, int) and f (char, int). Call the functions with arguments of 
type (int, char), (char,char) and (float, float). 
*/

#include<iostream>
using namespace std;

void func( int a,int b){
    cout<<"inside f(int ,int)"<<endl;
}
void func( char a,int b){
    cout<<"inside f(char ,int)"<<endl;
}


int main(){
    int i=1;
    char c='2';
    float f= 67.77;

    func(i,c);
    func(c,c);
    func(f,f);
}

/*//!Conclusion:- 

//?" error: call of overloaded 'func(float&, float&)' is ambiguous" ERROR

*/