/*
3. Implement a two dimensional array of integers using a) pointer to an array and b) array of pointers. Accept 
the value for the elements and print those. 

*/

#include<stdio.h>
#include<stdlib.h>
#define n 2
int main(){
    int* a[10];
    for(int i=0;i<n;i++){
        a[i]=(int*)malloc(sizeof(int)*n);
    }

    printf("Enter elements in a 2 x 2 array:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Element array[%d][%d]: ",i,j);
            scanf("%d",*(a+i)+j);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(a+i)+j));
        }printf("\n");
    }
}