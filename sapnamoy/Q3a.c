#include<stdio.h>
#include<stdlib.h>
int main(){
	
	
	int row_n,col_n;
	printf("enter row and col with space between them:");
	scanf("%d %d",&row_n,&col_n);

	int num_of_elements=row_n*col_n;
	int(*p)[column_n];
	p=(int*)malloc(sizeof(int)*num_of_elements);
	
	for(int row=0;row<row_n;row++){//taking the array
		for(int column=0;column<col_n;column++){
			printf("array[%d][%d] : ",row,column);
			scanf("%d",(p+row*row_n+column));
		}
	}

	for(int row=0;row<row_n;row++){//printing the array
		for(int column=0;column<col_n;column++){
			printf("array[%d][%d] = %d	|",row,column,*(p+row*row_n+column));
		}printf("\n");
	}

	
	
}
