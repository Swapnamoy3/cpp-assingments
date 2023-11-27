/*
1. Write a program that will have an integer variable and a pointer (say, p) pointing to it. Also have a pointer 
to pointer pointing to p. Take the value for the integer variable and print it using p, and pp. 

Name:- Swapnamoy Garai
Roll:- 002210501001
class:- CSE UG2
*/

#include<stdio.h>

int main(){
    int num;//integer
    int* p;//pointer to an integet
    int**pp;//pointer to an integer pointer 
    printf("Enter a number: ");
    scanf("%d",&num);
    p=&num;//storing address of num in p
    pp=&p;//storing address of p in pp

    printf("using integer variable: %d\n",num);
    printf("using pointer to an integer: %d\n",*p);
    printf("using pointer to an integer pointer: %d\n",**pp);
}