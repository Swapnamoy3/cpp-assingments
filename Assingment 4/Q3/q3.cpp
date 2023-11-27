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
    int * arr;
    int n;
public:

    //initializers

    ARRAY(int n,int initilizer){
        
        arr=new int[n];
        for(int i=0;i<n;i++) arr[i]=initilizer;
        this->n=n;
    }

    ARRAY (ARRAY& a){
        this->n=a.n;
        this->arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=a.arr[i];
        }
    }

    ARRAY(){
        arr=NULL;
        n=0;
    }   

    ARRAY(int* a,int n){
        this->n=n;
        this->arr=a;
        
    }

    //operations;

    ARRAY operator+(ARRAY& a){
        ARRAY res(max(n,a.n),0);
        
        for(int i=0;i<n;i++){
            res.arr[i]+=arr[i];
        }
        
        for(int i=0;i<a.n;i++){
            res.arr[i]+=a.arr[i];
        }

        return res;
    }

    ARRAY operator*(int c){
        ARRAY res(n,0);
        for(int i=0;i<n;i++)
        res.arr[i]=c*arr[i];

        return res;
    }

    

    int operator [](int i){
        return arr[i];
    }

    //utilities
    void printArray(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
};

ARRAY operator* (int c,ARRAY& a){
    ARRAY res;
    res=a*c;
    return res;
}




int main(){
    ARRAY a(10,4);
    ARRAY b(11,3);
    int arr[4]={1,2,3,4};
    ARRAY c(arr,4);
    cout<<"Array a: ";
    a.printArray();
    cout<<endl;
    cout<<"Array b: ";
    b.printArray();
    cout<<endl;

    ARRAY res;
    res=a*4;
    res=4*res;

    cout<<endl;

    // cout<<res[1]<<endl;

    cout<<"Array 4*a*4: ";
    res.printArray();



}