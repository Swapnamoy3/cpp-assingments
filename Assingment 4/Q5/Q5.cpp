/*

Modify the STRING class so that assigning/initializing a string by another will not
copy it physically but will keep a reference count, which will be incremented.
Reference value 0 means the space can be released.

*/



#include <iostream>
#include <stdio.h>
#include<cstring>
#include<stdio.h>
using std::cin;
using std::cout;
using std::endl;
// using namespace std;

class STRING{
    char * str;
    int* ref;
public:
    STRING(const char s[] = "")
    {   
        
        str=(char*)malloc(sizeof(char)*(strlen(s)+1));
        int i = 0;
        while (s[i] != '\0')
        {
            str[i] = s[i];
            // cout<<s[i];
            i++;
        }
        str[i] = '\0';

        ref=new int;
        (*ref)=0;
    }

    STRING( char str[]){
        this->str=str;
    }

    STRING(STRING & s){
        this->str=s.str;
        this->ref=s.ref;
        ++(*ref);
    }

    ~STRING(){
        --(*ref);
        if(ref==0){
            delete[] str;
        }
    }

    void print(){
        printf("%s",str);
    }

    void copyCount(){
        cout<<*(this->ref);
    }


    //comparison 

    STRING operator+(STRING& s){
        char* res=new char [sizeof(str)+sizeof(s.str)+1];
        int i=0;
        while(str[i]!='\0'){
            res[i]=str[i++];
        }
        
        int j=0;
        while(s.str[j]!='\0'){
            res[j+i]=s.str[j++];
        }

        res[i+j]='\0';

        STRING ans(res);
        return ans;
    }


    bool operator==(STRING& s){
        int i=0;
        while(str[i]!='\0' && s.str[i]!='\0'){
            if(str[i]!=s.str[i]){
                return false;
            }i++;
        }

        return (str[i]=='\0' and s.str[i]=='\0');
    }


    bool operator<=(STRING& s){
        int l1=strlen(str);
        int l2=strlen(s.str);

        int i=0;
        while(str[i]!='\0' && s.str[i]!='\0'){
            if(str[i]<=s.str[i++])
                continue;
            else
                return false;
                
            
            
        }

        return (l1<=l2);


    }

    bool operator>(STRING& s){
        return !operator<=(s);
    }

    bool operator>=(STRING& s){
        return (!operator<=(s) || operator==(s));
    }

    bool operator<(STRING& s){
        return !operator>=(s);
    }

    bool operator!=(STRING& s){
        return !operator==(s);
    }

    void print_copy_count(){
        cout<<endl<<(*ref)<<endl;
    }



};



int main(){
    // // char str[]="swap";
    // STRING s("Swap");
    // s.print();


    const char str[100] = "swapnamoy";

    STRING s(str);
    cout<<"STRING s: ";
    s.print();
    cout << endl;

    STRING s1(s);
    cout<<"STRING s1: ";
    s1.print();
    cout << endl;
    STRING res;
    res = s + s1;
    cout<<"STRING s+s1: ";
    res.print();

    s.print();


    cout<<"\nCheacking relationsl operators: \n";
    s.print();cout<<" < ";s1.print();
    cout <<" "<< (s < s1)<<endl;

    s.print();cout<<" > ";s1.print();
    cout <<" "<< (s > s1)<<endl;

    s.print();cout<<" <= ";s1.print();
    cout <<" "<< (s <= s1)<<endl;

    s.print();cout<<" >= ";s1.print();
    cout <<" "<< (s >= s1)<<endl;

    STRING s2(s1);
    cout<<"s2 coupies from s1 so copy count of s and s1:\n";
    s.print_copy_count();
    s1.print_copy_count();
}