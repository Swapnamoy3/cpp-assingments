/*
3.implement a two array of integers usuing a) pointer to an arrya

*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	
	int array[2][2];//declayring a static array
	int* p=(int*)array;//taking the address of 1st element a[0][0]
	
	printf("enter elements of 2x2 array in a row\n");
	for(int i=0;i<2;i++){//input array
		for(int j=0;j<2;j++)
		{
			scanf("%d",(p+i*2+j));//a[i][j] is calculating the i and j th pos using pointer arrithatic as *(*(a+i)+j) 
		}
	}

	for(int i=0;i<2;i++){//output array
		for(int j=0;j<2;j++){
			printf("%d ",(*(p+i*2+j)));
		}
		printf("\n");
	}
	
}
