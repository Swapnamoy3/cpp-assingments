/*
. Create a class for linked list. Consider a separate class NODE for basic node 
activities and use it in class for linked list.

*/

//*Basic activaties:-
/*
1. add node
2.del node
3.display node

*/
#include<iostream>
using namespace std;


class NODE{
    public:
    int info;
    NODE* next=NULL;
    NODE(int info){
        this->info=info;
        this->next=NULL;
    }

    

};

class List{
    NODE *head=NULL;
    public:

        void addNode(int info){
            if(head==NULL){
                head=new NODE(info);
                return;
            }

            
            NODE* curPtr=head;
            while(curPtr->next!=NULL) curPtr=curPtr->next;

            curPtr->next=new NODE(info);
        }

        void deleteNode(int key){
            if(head==NULL){
                cout<<"List is empty";
                return;
            }

            NODE* curPtr=head;
            NODE* prevPtr=NULL;
            while (curPtr!=NULL)
            {
                if(curPtr->info==key){
                break;}

                prevPtr=curPtr;
                curPtr=curPtr->next;
            }
            if(prevPtr==NULL){                                                                          
                head=curPtr->next;                                                                                      
                delete curPtr;
            }

            if(curPtr->info==key){
                prevPtr->next=curPtr->next;
                delete curPtr;
            }
        }

        void display(){
            if(head==NULL){cout<<"No list exist"; return;}

            NODE* currPtr=head;
            while(currPtr!=NULL){
                cout<<currPtr->info<<"->";
                currPtr=currPtr->next;
            }cout<<"NULL\n";
        }


};

int main(){
    List a;
    int option=0;
    while (option!=-1)
    {
        cout<<"Enter 1 for add node"<<endl;
        cout<<"Enter 2 for del node"<<endl;
        cout<<"Enter 3 for display list"<<endl;
        cout<<"Enter -1 for Quit"<<endl;


        cin>>option;

        switch (option)
        {
        case 1:
            int info;
            cout<<"Enter the data: ";
            cin>>info;

            a.addNode(info);
            break;

        case 2:
            int key;
            cout<<"Enter the key to delete: ";
            cin>>key;

            a.deleteNode(key);
            break;

        case 3:
            a.display();
            break;
        
        case -1:
            return 0;
            break;
        }
        
    }
    
}