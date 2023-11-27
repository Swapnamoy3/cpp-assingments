/*
In a library, for each book book-id, serial number (denotes copy number of a book), title, author, publisher and price are stored. Book-id and serial number together will be unique identifier for a book. Members are either student or faculty. Each member has unique member-id. Name, e-mail, address are also to be stored. For any transaction (book issue or return), members are supposed to place transactions slip. User will submit member-id, book-id, and serial number (only for book return). While processing a transaction, check the validity of the member. While issuing, availability of a copy of the book is to be checked. While returning a book, it is to be checked whether this copy was issued to the member or not. A student member can have 2 books issued at a point of time. For faculty members it is 10. Transaction information is to be stored like date of transaction, member-id, book-id, serial number, returned or not. An entry is made when book is issued and updated when the book is returned. For storing the information consider files.
Design the classes and implement. 
*/


#include<iostream>
using namespace std;
class book;
class Transaction_slip;

class bookList{
    book** bookArray;
    int n;
public: 
    bookList(){
        bookArray = new book* [100];
        n=0;
    }
    friend class book;
    friend void issue(Transaction_slip );
    friend void _return(Transaction_slip ,book& );


};

bookList Libery;


class member;
class memberList{
    member** memArray;
    int n;
public:
    memberList(){
        memArray= new member*[100];
        n=0;
    }

    friend class student;
    friend class faculty;
    friend void issue(Transaction_slip );
    friend void _return(Transaction_slip ,book& );

};
memberList records;

class book{
    int ook_id;
    int serialNumer;
    string title;
    string pulisher;
    int price;

public:
    book(int ook_id,int serialNumer,string title,string pulisher,int price){
        this-> ook_id = ook_id;
        this-> serialNumer = serialNumer;
        this-> title = title;
        this-> pulisher = pulisher;
        this-> price = price;
        Libery.bookArray[Libery.n++]=this;
    }
    friend void issue(Transaction_slip );
    friend void _return(Transaction_slip ,book& );

    void info(){
        cout<<"Title: "<<title<<endl;
        cout<<"Pulisher: "<<pulisher<<endl<<endl;
    }

};

class member{
protected:
    int memberId;
    string name;
    string email;
    string address;  
    book** issued_ooks;
    int n;
    int mx_n;

public:
    friend void issue(Transaction_slip );
    friend void _return(Transaction_slip ,book& );

    void books(){
        for(int i=0;i<n;i++){
            issued_ooks[i]->info();
        }
    }


};

class student :public member{
public:
    student(int memberId,string name,string email, string address){
        mx_n=2;
        this-> memberId = memberId;
        this-> name = name;
        this-> email = email;
        this-> address = address; 
        issued_ooks=0;
        records.memArray[records.n++]=this;
        issued_ooks= new book*[2];
        n=0;
    };

};

class faculty :public member{
public:
    faculty(int memberId,string name,string email, string address){
        mx_n=10;
        this-> memberId = memberId;
        this-> name = name;
        this-> email = email;
        this-> address = address; 
        issued_ooks=0;
        records.memArray[records.n++]=this;
        issued_ooks= new book*[10];
        n=0;
    };
};

class Transaction_slip{
    int memberId;
    int ook_id;
    int serialNumer;
public:
    Transaction_slip(int memberId,int ook_id,int serialNumer){
        this->memberId=memberId;
        this->ook_id=ook_id;
        this->serialNumer=serialNumer;
    }
    friend void issue(Transaction_slip );
    friend void _return(Transaction_slip ,book& );



};

void issue(Transaction_slip t){
    int i;
    for( i=0;i<records.n;i++){
        if(records.memArray[i]->memberId==t.memberId) break;
    }
    if(records.memArray[i]->memberId!=t.memberId){cout<<"memer do not exist"; return;}
    
    
    int j;
    for( j=0;j<Libery.n;j++){
        if(Libery.bookArray[j]->ook_id==t.ook_id) break;
    }
    if(Libery.bookArray[j]->ook_id!=t.ook_id){cout<<"book is not avilale"; return;}


    if(records.memArray[i]->mx_n<= records.memArray[i]->n) { cout<<"no more books can e given ";return;}

    records.memArray[i]->issued_ooks[records.memArray[i]->n++]=Libery.bookArray[j];
    cout<<"Book has been issued";

}


void _return(Transaction_slip t,book& b ){
    int i;
    for( i=0;i<records.n;i++){
        if(records.memArray[i]->memberId==t.memberId) break;
    }
    if(records.memArray[i]->memberId!=t.memberId){cout<<"memer do not exist"; return;}
    
    int j;
    int k;
    for(j=0;j<Libery.n;j++){
        for( k=0;k<records.memArray[i]->n;k++){
            if(records.memArray[i]->issued_ooks[k]->ook_id==b.ook_id and 
            records.memArray[i]->issued_ooks[k]->serialNumer==b.serialNumer) break;
        }
    }
    if(records.memArray[i]->issued_ooks[k]->ook_id!=b.ook_id || 
            records.memArray[i]->issued_ooks[k]->serialNumer!=b.serialNumer) {cout<<"member has not issued eith this version of book";return;}
    




    records.memArray[i]->issued_ooks[k]=0;
    cout<<"Book has been returned";

}

int main(){
    book maths(123,453,"special maths","parul",450);
    book english(143,456,"special english","parul",350);
    student s1(4568,"student s","s@gmail.com","s lane more");
    Transaction_slip t(4568,123,453);
    issue(t);
    cout<<endl;
    s1.books();
    cout<<endl;
    _return(t,maths);
}
