#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[2][2];
    arr[1][0]=1;
    printf("%d",*(*(arr+1)));
}