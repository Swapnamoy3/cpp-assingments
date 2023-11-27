//Name:- Swapnamoy garai
//roll no:-002210501002

//Q2.implement one diamentional array of integers wherw size of array size will be provided during run time.Accet the value for the elements and print those using pointers.

#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;//size of attry
	scanf("%d",&n);//taking input
	int *p;//declaring an pointer to an integer

	p=(int*)malloc(n*sizeof(int));//making a dynamic memory slot of size of integers times n and casting the address it returns into int*


	for(int i=0;i<n;i++){
		scanf("%d",(p+i));// taking values of the array using the pinter
	}

	for(int i=0;i<n+1;i++){
		printf("%d\n",*(p+i));// printing values of the array using the pinter
	}
}
