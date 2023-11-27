/*
Store name and age of number of persons (number provided at run time). Collect the data and display data 
in the ascending order of age. Implement without using structure. Write functions for memory allocation of 
the list, sorting and display of data. 
*/

#include<stdio.h>
#include<stdlib.h>

int* allocateIntArray(int n){
    return (int*)malloc(sizeof(int)*n);
}

char** allocateNameArr(int n){
    char** nameArr=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        nameArr[i]=(char*)malloc(sizeof(char)*31);
    }

    return nameArr;
}

void sort(int* arr,char**name,int n){
    for(int i=0;i<n;i++){
        for(int j=i+i;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

                char* t=name[i];
                name[i]=name[j];
                name[j]=t;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int* arr=allocateIntArray(n);
    char**name=allocateNameArr(n);

    for(int i=0;i<n;i++){
        scanf("%d %s",&arr[i],name[i]);
    }

    sort(arr,name,n);
    
    for(int i=0;i<n;i++){
        printf("%d %s",arr[i],name[i]);
    }
}