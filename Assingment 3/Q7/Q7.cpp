/*
Design a class TIME which stores hour, minute and second. The class should have 
the methods to support the following: 
- User may give the time value in 24-hour format. 
- User may give the time value in AM/PM format 
- Display the time in 24-hour format. 
- Display the time in AM/PM format. 
- User may like to add minute with a time value. 


*/

#include<iostream>
using namespace std;

class TIME{
    int hour;
    int miniute;
    int second;

    public:
        void inputTime(){
            cout<<"Enter seconds: ";
            cin>>second;
            cout<<"Enter minutes: ";
            cin>>miniute;
            
            int format;
            cout<<"24 or 12 hour format :";
            cin>>format;
            if(format==24) {
                cout<<"enter the hours: ";
                cin>>hour;
            }else{
                string s;
                cout<<"AM or PM";
                cin>>s;

                cout<<"enter the hours: ";
                cin>>hour;
                hour+=(s=="PM")*12;

            }
            
        }

        void displayIn24format(){
            if(hour<10) cout<<"0";
            cout<<hour<<":";
            if(miniute<10) cout<<"0";
            cout<<miniute<<":";
            if(second<10) cout<<"0";
            cout<<second;

        }

        void displayIn12format(){
            if(hour==12){
                if(hour<10) cout<<"0";
                cout<<hour<<":";
                if(miniute<10) cout<<"0";
                cout<<miniute<<":";
                if(second<10) cout<<"0";
                cout<<second<<" PM";
            }
            else if(hour>12){
                if(hour<10) cout<<"0";
                cout<<hour-12<<":";
                if(miniute<10) cout<<"0";
                cout<<miniute<<":";
                if(second<10) cout<<"0";
                cout<<second<<" PM";
            }else{
                if(hour<10) cout<<"0";
                cout<<hour<<":";
                if(miniute<10) cout<<"0";
                cout<<miniute<<":";
                if(second<10) cout<<"0";
                cout<<second<<" AM";
            }
        }

        void addMinutes(){
            int m;
            cout<<"Enter minutes shoulh be added: ";
            cin>>m;

            miniute+=m;
            hour+=(miniute/60);
            miniute%=60;
        }
};

int main(){
    TIME t;
    while(1){
        int choice;
        cout<<"\nPress 1 for entering time"<<endl;
        cout<<"Press 2 for displaying time in 24 format"<<endl;
        cout<<"Press 3 for isplaying time in 12 format"<<endl;
        cout<<"Press 4 for adding min"<<endl;
        cout<<"Press 0 for quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            t.inputTime();
            break;
        case 2:
            t.displayIn24format();
            break;
        case 3:
            t.displayIn12format();
            break;
        case 4:
            t.addMinutes();
            break;
        
        default:
            return 0;
            break;
        }
    }

}