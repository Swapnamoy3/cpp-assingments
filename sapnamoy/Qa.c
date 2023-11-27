#include<stdio.h>
#include<stdlib.h>
int main(){
	
	int* (*p)[2]
	int arr[2][2];
	p=&arr;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&p[i][j]);
	}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%d",p[i][j]);
	}
	}

	
	
}
