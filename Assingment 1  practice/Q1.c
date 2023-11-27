/*
2. Implement a one dimensional array of integers where array size of the array will be provided during 
runtime. Accept the value for the elements and print those using pointers. 

Name:- Swapnamoy Garai
Roll:- 002210501001
class:- CSE UG2
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    int *p;
    int** pp;
    p=&n;
    pp=&p;

    printf("p has: %d and pp has: %d",*p,**pp);
}