//Name:- Swapnamoy garai
//roll no:-002210501001

/*implement a two diamentional arrayof integers using array of pointers.Accept the value of elements and print those*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int row_n,col_n;
	printf("enter row and col with space between them:");
	scanf("%d %d",&row_n,&col_n);
	
	int**array2d;
	array2d=(int**)malloc(sizeof(int*)*row_n);//array of pointers of int* type

	for(int row=0;row<row_n;row++){
		array2d[row]=(int*)malloc(sizeof(int)*col_n);//each fo pointers of int t ype
	}

	for(int row=0;row<row_n;row++){//taking the array
		for(int column=0;column<col_n;column++){
			printf("array[%d][%d] : ",row,column);
			scanf("%d",&array2d[row][column]);
		}
	}
	
	for(int row=0;row<row_n;row++){//printing the array
		for(int column=0;column<col_n;column++){
			printf("array[%d][%d] = %d	|",row,column,array2d[row][column]);
		}printf("\n");
	}

	
	
}
