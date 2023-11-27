/*
inmplementing 2 d array usig a)dyamic allocation
                             b)functional implementation for taking inputs ,creating array,and
                              printing output

*/
#include<stdio.h>
#include<stdlib.h>



int* createArray(int n ){
    int * p=(int*)malloc(sizeof(int)*n);//malloc allocates 4*n bytes and returns the  adderss of first 4
    return p;
}

void takeInput(int* p,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
}

void outputArray(int * p,int n){
    for(int i=0;i<n;i++){
        printf("%d",p[i]);
    }
}
 
int**create2DArray(int row_size,int col_size){
    int **p=(int**)malloc(sizeof(int*)*row_size);//creating an array of int* pointer using malloc
    //int**p a pointer that allocates a contigious memory for int* element
    
    for(int i=0;i<row_size;i++){
        p[i]=(int*)malloc(sizeof(int)*col_size);//setting int* type to first element of array which malloc creates 
    }

    return p;
}

void takeInput2DArray(int**p,int row_size,int col_size){
    for(int i=0;i<row_size;i++){//taking input
        for(int j=0;j<col_size;j++){
            scanf("%d",&p[i][j]);
        }
    }
}

void output2DArray(int**p,int row_size,int col_size){
    for(int i=0;i<row_size;i++){//giving output
        for(int j=0;j<col_size;j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}

int main(){

    //functional implementation of 2Darray
   int size;
//    printf("enter the size of 1 d array");
   scanf("%d",&size);
   int * p=createArray(size);//this functio returns a pointer to 0 th element of an newly created array using malloc

   takeInput(p,size);//takes input for the array 
   outputArray(p,size);//takes output of the array 




}