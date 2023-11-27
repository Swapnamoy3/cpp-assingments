//Name:- Swapnamoy garai
//roll no:-002210501001
//problem-statement: write an varible that will have an integer and a pointer pointing to it.also have a pointer to pointer pointing to p .
//Takethe value for the integer take the value for integer variable using pointer and pointer(p) to pointer(pp).

#include<stdio.h>
int main(){
	int a;// variable of number
	int*p;//pointer to the number
	int **pp;//pointer to the pointer of number
	scanf("%d",&a);//taking input
	p=&a;//assing address of a to p
	pp=&p;//storing address of p to pp
	printf("%d\n",*p);//printing value of adderss stored in p
	printf("%d",**pp);//printing value of ,value of adderss stored in p

}
