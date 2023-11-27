/*
Design the class(es) for the following. Each account has account number and 
balance amount. A list of account is to be maintained where one can add and 
find account, display information of all accounts. While adding, account number 
must be unique. Withdraw object has account number (must exist) and amount 
(will not exceed balance amount of corresponding account). Withdraw object will 
update the balance of corresponding account in the list. User will be able to
search and view account, add account and withdraw money from the 
account. Implement your design. Use friend function wherever required and 
again, modify your implementation to avoid friend function. 
*/


/* Ojectives: 
• Account
    *- account nummer
    *- balance
    *- view an account


• List of account 
    *- can be searched for a pecific account
    *- info of a specific account can e displayed
    - while an new account is created it ensures that account numer is Unique 
    !(in pograme)

• Withdraw object
    - has an existinf account number and and makes chandes to the account 
    

• system / pograme
    - search and view an account
    - add account
    - withdraw money

//!
    - use Friend function 
    - modify it so that there is no need of friend function


*/


/*
! how to check if an account with same account number exist
    Solution :- check when the pograme is collrecting athe account number

*/

#include<iostream>
using namespace std;


class ACCOUNT_LIST{
    ACCOUNT* list[100];
    int top;

public:
    ACCOUNT_LIST(){top=0;}

    friend class ACCOUNT;

    ACCOUNT* searchAccount(string accountNumer){
        for(int i=0;i<top;i++){
            if((list[i])->getAccountNumer()==accountNumer){
                return list[i];
            }
        }
        return NULL;
    }

    


};

ACCOUNT_LIST l;


class ACCOUNT{
    string accountNumer;
    float balance;

public:
    ACCOUNT(string accountNumer,float balance){
        this->accountNumer=accountNumer;
        this->balance=balance;
        l.list[l.top++]=this;
    }

    string getAccountNumer(){
        return accountNumer;
    }

    float getBalance(){
        return balance;
    }

    void showAccount(){
        cout<<"Account Numer: "<<accountNumer<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    void updateAccount(float amount){
        balance+=amount;
    }

};


class WITHDRAW{
    string accountNumber;
    float withdrawAmmount;
public:
    WITHDRAW(string accountNumber,float withdrawAmmount){
        this->accountNumber=accountNumber;
        this->withdrawAmmount=withdrawAmmount;

        ACCOUNT* a=(ACCOUNT*)(l.searchAccount(accountNumber));
        (*a).updateAccount(-withdrawAmmount);
    }


};

int main(){
    int option=0;
    while(option!=-1){
        cout<<"Enter 1 for making an account\n";
        cout<<"Enter 2 for search and view an account\n";
        cout<<"Enter 3 for withdraw from an account\n";
        cout<<"Enter -1 for quiting\n";

        cin>>option;

        switch (option)
        {
        case 1:
           { string accNum; 
            cout<<"Enter the account number: ";
            cin>>accNum;

            if(!l.searchAccount(accNum)){
                cout<<"An account with same account numer already exist  ";
                break;
            }

            float balance;
            cout<<"Enter balance of account: ";
            cin>>balance;

            
            new ACCOUNT(accNum,balance);}
            break;

        case 2:{
            string accNum; 
            cout<<"Enter the account number: ";
            cin>>accNum;
            ACCOUNT* a=(ACCOUNT*)(l.searchAccount(accNum));

            if(!a){
                cout<<"No such account exist  ";
                break;
            }

            a->showAccount();

            break;
        }

        case 3:{
            string accNum;
            cout<<"Enter the account number: ";
            cin>>accNum;
            ACCOUNT* a=(ACCOUNT*)(l.searchAccount(accNum));

            if(!a){
                cout<<"No such account exist  ";
                break;
            }

            float balance;
            cout<<"Enter amount to withdraw: ";
            cin>>balance;

            if(a->getBalance()<balance){
                cout<<"Not enough balance to withdraw"<<endl;
                break;
            }

            new WITHDRAW(accNum,balance);
        
        }
        break;

        
        default:
            return 0;
        }
    }
}