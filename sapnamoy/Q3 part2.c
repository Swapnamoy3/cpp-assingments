// 3.implement a two array of integers usuing b)array of pointers

#include<stdio.h>
#include<stdlib.h>
int main(){
    int row_size,col_size;
    printf("enter row and column size \n");
    scanf("%d %d",&row_size,&col_size);//taking input and output size

    int **p=(int**)malloc(sizeof(int*)*row_size);//creating an array of int* pointer using malloc
    //int**p a pointer that allocates a contigious memory for int* element
    
    for(int i=0;i<row_size;i++){
        p[i]=(int*)malloc(sizeof(int)*col_size);//setting int* type to first element of array which malloc creates 
    }

    for(int i=0;i<row_size;i++){//taking input
        for(int j=0;j<col_size;j++){
            printf("enter elemets of %d th row with space b/w them : ",i);
            scanf("%d",&p[i][j]);
        }
    }

    for(int i=0;i<row_size;i++){//giving output
        for(int j=0;j<col_size;j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}