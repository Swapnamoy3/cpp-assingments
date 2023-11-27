/*
Write a function that will have income and tax rate as arguments and will return 
tax amount. In case tax rate is not provided it will be automatically taken as 10%. 
Call it with and without tax rate. 
*/

#include<iostream>
using namespace std;

double tax(double income,double taxRate=10){
    return income*taxRate/100;
}

int main(){
    double income, rate_precentage;
    cout<<"Enter the income: ";
    cin>>income;
    cout<<"Enter the rate of income tax: ";
    cin>>rate_precentage;
    
    cout<<"The tax is ";
    if(rate_precentage==-1) cout<<tax(income);
    else cout<<tax(income,rate_precentage); 

}