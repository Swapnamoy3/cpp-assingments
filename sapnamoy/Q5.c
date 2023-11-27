/*
5.store name and age of number of person(provided at run time) and using dynamic allocation.
-->Collect data and display data in the ascending order of age.
-->implement without using structure
*/
#include<stdio.h>
#include<stdlib.h>


int* createArrayINT(int n ){
    int* p=(int*)malloc(sizeof(int)*n);//malloc allocates 4*n bytes and returns the  adderss of first 4
    return p;
}

char** createArrayWORDS(int n ){
    char** words=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        words[i]=(char*)malloc(sizeof(char)*31);
    }
    return words;
}


void sort(int* ageArray,char** words,int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ageArray[i]>ageArray[j]){
                int temp=ageArray[i];
                ageArray[i]=ageArray[j];
                ageArray[j]=temp;

                char* temp_words=words[i];
                words[i]=words[j];
                words[j]=temp_words;
            }
        }
    }
    
}

int main(){
    int n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int *age=createArrayINT(n);
    char** words=createArrayWORDS(n);

     for(int i=0;i<n;i++){
        scanf("%d %s",&age[i],words[i]);
    }


    sort(age,words,n);

   for(int i=0;i<n;i++){
        printf("%d %s\n",age[i],words[i]);
    }


}