/*
Each cricketer has name, date of birth and matches played. Cricketer may be a bowler or batsman. For a bowler, number of wickets taken, average economy is stored. For a batsman, total runs scored, average score is stored.  A double wicket pair is formed taking a bowler and a batsman. An all-rounder is both a bowler and batsman. Support must be there to show the details of a cricketer, bowler, batsmen, all-rounder and the pair.
Design the classes and implement.

*/
#include<iostream>
using namespace std;

class Cricketer{
protected:
    string name;
    int date;
    int matches_played;  
public:
    Cricketer(){};
    Cricketer(string name,int date,int matches_palyed){
        this->name=name;
        this->date=date;
        this->matches_played=matches_played;
    }

    virtual void printDATA(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"matches_played: "<<matches_played<<endl<<endl;
    }
};

class Bowler:public Cricketer{
    int no_of_wickets_taken;
    int economy;
public:
    Bowler(string name,int date,int matches_palyed,int no_of_wickets_taken,int economy):Cricketer( name,date, matches_palyed){
        this->no_of_wickets_taken=no_of_wickets_taken;
        this->economy=economy;
    }

    void printDATA(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"matches_played: "<<matches_played<<endl;
        cout<<"no_of_wickets_taken: "<<no_of_wickets_taken<<endl;
        cout<<"economy: "<<economy<<endl<<endl;
    }
};


class Batsman:public Cricketer{
    int total_runs;
    int avg_runs;
public:
    Batsman(string name,int date,int matches_palyed,int total_runs,int avg_runs):Cricketer( name,date, matches_palyed){
        this->total_runs=total_runs;
        this->avg_runs=avg_runs;
    }

    void printDATA(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"matches_played: "<<matches_played<<endl;
        cout<<"total_runs: "<<total_runs<<endl;
        cout<<"avg_runs: "<<avg_runs<<endl<<endl;
    }
};


class Double_wicket_pair:public Cricketer{
public:
    Double_wicket_pair(string name,int date,int matches_palyed):Cricketer( name,date, matches_palyed){    }
};

class All_rounder:public Cricketer{
public:
    All_rounder(string name,int date,int matches_palyed):Cricketer( name,date, matches_palyed){    }
};


int main(){
    Cricketer* c;
    All_rounder a("swap",12,456);
    Batsman b("xy",13,45,789,105);
    c=&a;
    c->printDATA();
    c=&b;
    c->printDATA();

}