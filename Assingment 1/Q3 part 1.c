#include<stdio.h>

//a) pointer to an array implementation
int main(){
int a[2][2];
int *p=(int*)a;

printf("Enter elements in a 2 x 2 array:\n");
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("Element array[%d][%d]: ",i,j);
        scanf("%d ",&a[i][j]);
    }

}


printf("Elements are: \n");
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("%d ",*(p+i*2+j));
    }
    printf("\n");
}
}