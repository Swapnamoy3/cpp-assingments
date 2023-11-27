#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    int n;
    printf("Enter the numer of elements: ");
    scanf("%d",&n);

    p=(int*)malloc(sizeof(int)*n);

    printf("Enter the terms: ");
    for(int i=0;i<n;i++){
        scanf("%d",p+i);
    }

    printf("Elements are: ");
    for(int i=0;i<n;i++){
        printf("%d ",*(p+i));
    }

}