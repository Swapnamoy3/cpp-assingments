/*

Design the class(es) for the following scenario: 
- An item list contains item code, name, rate, and quantity for several items. 
- Whenever a new item is added in the list uniqueness of item code is to be checked. 
- Time to time rate of the items may change. 
- Whenever an item is issued or received existence of the item is checked and quantity is updated. 
- In case of issue, availability of quantity is also to be checked. 
- User may also like to know price/quantity available for an item. 


*/
#include<iostream>
using namespace std;

class item{
    public:
    int code;
    char name[31];
    int rate;
    int quantity;
};

class NODE{
    public:
    item i;
    NODE* next=NULL;
};

class list{
    NODE* head=NULL;
    public:

    void addItem(){        
        item tempItem;
        cout<<"Enter the code,name,price,and quantity of the item: ";
        cin>>tempItem.code;
        cin>>tempItem.name;
        cin>>tempItem.rate;
        cin>>tempItem.quantity;

        if(head==NULL){
            head=new NODE;
            head->i=tempItem;
            return;
        }

        NODE* headPtr=head;
        while(headPtr->next!=NULL) {
            if(headPtr->i.code==tempItem.code){
                cout<<"Item already exist";
                return;
            }
            headPtr=headPtr->next;
        }

        headPtr->next=new NODE;
        (headPtr->next)->i=tempItem;
        return;        
    }

    void deleteItem(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }

        int code;
        cout<<"Enter the code of the item that you want to delete: ";
        cin>>code;

        NODE* headPtr=head;
        NODE* prevPtr=NULL;
        bool found=false;
        while (headPtr!=NULL)
        {   
            if(headPtr->i.code==code){
                found=true;
                break;}

            prevPtr=headPtr;
            headPtr=headPtr->next;
        }

        if(found && headPtr->next==NULL){
            delete headPtr;
            head=NULL;
            return;
        }

        if(!found){ cout<<"No such item exist";}
        else{
            prevPtr->next=headPtr->next;
            delete headPtr;
        }
        



        
    }

    void displayList() {
        NODE* headPtr=head;

        while(headPtr!=NULL){
            cout<<"\nitem code: "<<headPtr->i.code; 
            cout<<"\nitem name: "<<headPtr->i.name; 
            cout<<"\nitem price: "<<headPtr->i.rate; 
            cout<<"\nitem quantity: "<<headPtr->i.quantity;
            cout<<"\n|" ;

            headPtr=headPtr->next;
        }
        cout<<"\nNULL\n";
    }

    void updateRate(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }

        int code;
        cout<<"Enter the code of the item to be updated: ";
        cin>>code;

        NODE* headPtr=head;
        
        while (headPtr!=NULL)
        {
            if(headPtr->i.code==code) break;
            headPtr=headPtr->next;
        }
        if(headPtr==NULL){cout<<"No such item exist";return;}
        cout<<"Enter new rate: ";
        cin>>headPtr->i.rate;
    }

    void reissue(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }

        int code;
        cout<<"Enter the code of the item to be re-issued: ";
        cin>>code;
        
        NODE* headPtr=head;
        while (headPtr!=NULL)
        {
            if(headPtr->i.code==code) break;
            headPtr=headPtr->next;
        }
        if(headPtr==NULL){cout<<"No such item exist";return;}
        cout<<"Item exist. Enter new quantity: ";
        cin>>headPtr->i.rate;

    }

    void checkAvailibility(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }

        int code;
        cout<<"Enter the code of the item : ";
        cin>>code;

        NODE* headPtr=head;
        while (headPtr!=NULL)
        {
            if(headPtr->i.code==code) break;
            headPtr=headPtr->next;
        }

        if(headPtr->i.quantity>0)
        cout<<"Available";
        else cout<<"Not available";

    }

    void itemInfo(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }

        int code;
        cout<<"Enter the code of the item: ";
        cin>>code;
        
        NODE* headPtr=head;
        while (headPtr!=NULL)
        {
            if(headPtr->i.code==code) break;
            headPtr=headPtr->next;
        }
        if(headPtr==NULL){cout<<"No such item exist";return;}

        cout<<"Item price: "<<headPtr->i.rate<<"\n";
        cout<<"Item quantity: "<<headPtr->i.quantity<<"\n";

    }



};



int main(){
    list l;

    int option=0;
    while (1)
    {

        cout<<"\n";
        cout<<"Enter 1 for adding item\n";
        cout<<"Enter 2 for deleting item\n";
        cout<<"Enter 3 for diaplay list\n";
        cout<<"Enter 4 for update rate item\n";
        cout<<"Enter 5 for re-issue item\n";
        cout<<"Enter 6 for ablibility item\n";
        cout<<"Enter 7  for info of item\n";
        cout<<"Enter -1 for quiting\n";
        cin>>option;

        switch (option)
        {
        case 1:
            l.addItem();
            break;
        case 2:
            l.deleteItem();
            break;
        case 3:
            l.displayList();
            break;
        case 4:
            l.updateRate();
            break;
        case 5:
            l.reissue();
            break;
        case 6:
            l.checkAvailibility();
            break;
        case 7:
            l.itemInfo();
            break;
        
        default:
        return 0;
            break;
        }
    }
    
}