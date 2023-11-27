/*
Implement a one dimensional array of integers where array size of the array will be provided during 
runtime. Accept the value for the elements and print those using pointers. 
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int *p=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",p+i);
    for(int i=0;i<n;i++)printf("%d",*(p+i));
}