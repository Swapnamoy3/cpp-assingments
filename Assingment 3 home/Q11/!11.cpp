/*
. Create a class for linked list. Consider a separate class NODE for basic node 
activities and use it in class for linked list.

*/

//*Basic activaties:-
/*
1. add node
2.del node
3.edit node
4.seatch node
5.make a new list
*/
#include<iostream>
using namespace std;


class NODE{
    int info;
    NODE* next=NULL;
    public:
    void take_info(int a){
        info=a;
    }
    void take_next(NODE* a){
        next=a;
    }
};

class List{
    NODE* head;
    public:
    void createList(int info){
        if(head!=NULL){
            cout<<"this list alreadt exist";
            return;
        }

        head=new NODE();
        head->take_info(info);
    }
};