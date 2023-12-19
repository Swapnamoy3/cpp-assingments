#include<stdio.h>
int main(){
    int (*p)[5];
    int arr[10][10];
    p=arr;
    printf("%d\n",p++);
    printf("%d",p);
}