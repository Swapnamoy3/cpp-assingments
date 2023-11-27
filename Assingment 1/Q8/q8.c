#include<stdio.h>
#include<stdlib.h>

/*.  Consider an array that stores roll, name, and score of number of students. Develop a function to sort the 
array. User of sort() will develop the comparison function for sorting on roll/score and ascending or 
descending order and reuse the same sort() function. 
 */

typedef struct{
    char name[31];
    int roll;
    int score;
}student;

void sort(student arr[],int size,int (*f)(student,student)){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){

            if(f(arr[i],arr[j])){
                student temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int assendingByRoll(student s1,student s2){
    return s1.roll>s2.roll;
}
int deseningByRoll(student s1,student s2){
    return s1.roll<s2.roll;
}
int assendingByScore(student s1,student s2){
    return s1.score>s2.score;
}
int desendingByScore(student s1,student s2){
    return s1.score<s2.score;
}

int main(){

    student arr[3];
    for(int i=0;i<3;i++){
        printf("Enter roll name and score of student in order\n");
        scanf("%d %s %d",&arr[i].roll,&arr[i].name,&arr[i].score);
    }

    int isRoll;
    int isAssending;
    
    printf("Enter 1 if sort by roll else enter 0\n");
    scanf("%d",&isRoll);

    printf("Enter 1 if assending else enter 0\n");
    scanf("%d",&isAssending);

    if( isRoll && isAssending) sort(arr,3,assendingByRoll);
    if( isRoll && !isAssending) sort(arr,3,deseningByRoll);
    if( !isRoll && isAssending) sort(arr,3,assendingByScore);
    if( !isRoll && !isAssending) sort(arr,3,desendingByScore);

    
    for(int i=0;i<3;i++){
        printf("%d %s %d\n",arr[i].roll,arr[i].name,arr[i].score);
    }


}