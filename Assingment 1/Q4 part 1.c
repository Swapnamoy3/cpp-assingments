#include<stdio.h>
#include<stdlib.h>

int* create_Array(int n){
    int *p=malloc(sizeof(int)*n);
}

void takeValues(int * p,int n){
    printf("Enter the elements of arrar: ");
    for(int i=0;i<n;i++){
        scanf("%d",p+i);
    }
}

void printArray(int * p,int n){
    printf("Elements of array: ");
    for(int i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
}

int** create2Darray(int row_n,int col_n){
    int **p=(int **)malloc(sizeof(int*)*row_n);
    for(int i=0;i<row_n;i++){
        p[i]=(int*)malloc(sizeof(int)*col_n);
    }
}

void takeValues2D(int ** p,int row_n,int col_n){
    for(int i=0;i<row_n;i++){
        for(int j=0;j<col_n;j++){
            scanf("%d",*(p+i)+j);
        }
    }
}

void print2DArray(int ** p,int row_n,int col_n){
    for(int i=0;i<row_n;i++){
        for(int j=0;j<col_n;j++){
            printf("%d",*(*(p+i)+j));
        }
    }
}


int main(){
 int n;
 scanf("%d",&n);
 int*p =create_Array(n);
 takeValues(p,n);
 printArray(p,n);
}