#include<iostream>
using namespace std;

class customer{
    int id ;
    char name[31];
    int last_reading=0;
    int current_reading=0;
    static int meter_rent;
    static int consumption_rate;

    public:

    customer(int id,char namme[]){
        this->update();
        id=id;
    }

    void update(){
        last_reading=current_reading;
        cin>>current_reading;
    }

    void bill(){
        cout<<meter_rent+(current_reading-last_reading)*consumption_rate;
    }

    static void change_rent(){
        cin>>meter_rent;
    } 
    static void change_rate(){
        cin>>consumption_rate;
    } 
};

int customer::meter_rent=10;
int customer::consumption_rate=110;

int main(){

}