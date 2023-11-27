/*2. Write a function max (a, b) that will return the reference of larger value. Store the 
returned information to x where x is a i) variable of type a or b, ii) variable 
referring to type of a or b. In both the cases modify x. Check also the values of a 
and b. */

#include<iostream>
using namespace std;

int& max(int & a,int &b){
    if(a>=b) return a;
    return b;
}

int main(){
    int a,b;
    cout<<"Enter values of a and b: ";
    cin>>a>>b;

    int x=max(a,b);
    int& x_ref=max(a,b);

    cout<<"x :"<<x<<" x_ref: "<<x_ref<<endl;

    cout<<"Enter new values of a and b: ";
    cin>>a>>b;

    cout<<"x :"<<x<<" x_ref: "<<x_ref<<endl;


}
