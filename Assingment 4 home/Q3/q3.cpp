/*
 Design an ARRAY class with the following features: 
    a. Array object may be declared for a specific size and a value for initializing all the elements. If this it is to be assumed as a 0. 
    b. An array object may be declared and initialized with another object. 
    c. An array object may be declared and initialized with another array (not the object, standard array as in C language). 

Let a and b are two objects: 
    i. a+b will add corresponding elements. 
    ii. a=b will do the assignment. 
    iii. a[I] will return the ith element of the object. 
    iv. a*5 or 5*a will multiply the element with 5. 


*/

#include<iostream>
using namespace std;

class ARRAY{
    int size;
    int * arr;
    public:
    ARRAY(int n=0,int init=0){
        n=size;
        int a[n];
        for(int i=0;i<size;i++){
            a[i]=init;
        }

        arr=a;

    }
    ARRAY(int a[],int n){
        arr=a;
        size=n;
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }

    ARRAY operator + (ARRAY& b){
        


    }


};

int main(){

    int arr[6]={1,2,3,4,5,6};
    
    ARRAY a(arr,6);
    ARRAY b=a;
    // a.display();
    b.display();
    cout<<endl;
    b=a+b;
    b.display();

}