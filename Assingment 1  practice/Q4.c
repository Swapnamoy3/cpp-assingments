/*
Implement the programs in Q.2 and 3 breaking it into functions for i) getting the dimensions from user, ii) 
dynamic memory allocation, iii) accepting the values and iv) printing the values. 
*/

#include<stdio.h>
#include<stdlib.h>
void pointerToarray(int row,int col){
    int (*arr)[col]=(int (*)[col])malloc(sizeof(int)*col*row);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d",arr[i][j]);
        }
    }
}

void arrOFPointers(int n,int m){
    int** arr=(int**)malloc(sizeof(int*)*n);
    for(int j=0;j<n;j++){
        arr[j]=(int*)malloc(sizeof(int)*m);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",arr[i][j]);
        }
    }
}

int main(){
arrOFPointers(2,2);
}