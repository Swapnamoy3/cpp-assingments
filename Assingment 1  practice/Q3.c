/*
Implement a two dimensional array of integers using a) pointer to an array and b) array of pointers. Accept 
the value for the elements and print those. 
*/

#include<stdio.h>
#include<stdlib.h>
// int main(){
//     int a[2][2]={{1,2},{3,4}};
//     int (*arr)[2]=a;

//     for(int i=0;i<2;i++){
//         for(int j=0;j<2;j++){
//             scanf("%d",*(arr+i)+j);
//         }

//     }
//     for(int i=0;i<2;i++){
//         for(int j=0;j<2;j++){
//             printf("%d",*(*(arr+i)+j));
//         }
//         printf("\n");

//     }
// }

int main(){
    int* p[2];
    int r1[2]={1,2};
    int r2[2]={3,4};
    p[0]=r1;
    p[1]=r2;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d",*(*(p+i)+j));
        }
        printf("\n");

    }
}