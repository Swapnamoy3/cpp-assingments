/*
Design a BALANCE class with account number, balance and date of last update.
Consider a TRANSACTION class with account number, date of transaction,
amount and transaction type (W for withdrawal and D for deposit). If it is a
withdrawal check whether the amount is available or not. Transaction object will
make necessary update in the BALANCE class.
*/

/*//!Notes
- BALANCE class :
- account number, balance and date of last update

- TRANSACTION:
- account number, date of transaction, amount and transaction type


*/
#include<iostream>

//*managing decleration
void* list[100];
int topPtr=0;


//*main pogramme

using namespace std;

class Date{
    int date;
    int month;
    int year;

    public:

    Date(int d=0,int m=0,int y=0){
        date=d;
        month=m;
        year=y;
    }

    void printDate(){
        cout<<date<<" / ";
        cout<<month<<" / ";
        cout<<year<<endl;
    }

    void getDate(){
        cout<<date<<" / "<<month<<" / "<<year<<endl;
    }
};


class BALANCE{
    int accountNumber;
    int balance;
    Date date_of_last_update;

    public:
    BALANCE(int acc,int bal,Date d){
        accountNumber=acc;
        balance=bal;
        date_of_last_update=d;
        list[topPtr++]=this;
    }

    void showInfo(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
        date_of_last_update.printDate();
    }

    int accNum(){
        return accountNumber;
    }


    void updateBalance(int b,Date d){
        balance+=b;
        Date date_of_last_update=d;
    }


};

class TRANSACTION{
    int accountNumber;
    Date date_of_transaction;
    int amount;
    char typeOfTrans;

    public:
    TRANSACTION(int accNo,Date d,int a, char transType ){
        accountNumber=accNo;
        date_of_transaction=d;
        amount=a;
        typeOfTrans=transType;

        bool found=false;
        BALANCE *b;
        for(int i=0;i<topPtr;i++){
            b=(BALANCE*)(list[i]);
            if((*b).accNum()==accountNumber){
                found=true;
                break;
            }
        }

        if(found ){
            if(typeOfTrans=='W')
            (*b).updateBalance(-a,date_of_transaction);
            else
            (*b).updateBalance(a,date_of_transaction);
        }else{
            cout<<"balance account not found";
        }
    }



};

int main(){

    Date d(20,4,2003);
    BALANCE b(123,1000,d);
    BALANCE c(143,1500,d);

    c.showInfo();
    // d.getDate();
    TRANSACTION t(143,d,500,'W');     
    c.showInfo();



    


}
