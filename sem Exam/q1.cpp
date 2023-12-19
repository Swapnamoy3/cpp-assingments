// #include<iostream>
// #include<cstring>
// #include<fstream>
// using namespace std;

// class item{
//     int item_code;
//     char name[31];
//     float price;
// public:
//     friend class itemFile;
//     void input(){
//         cout<<"\n\n\nenter item-name ";
//         cin>>name;
//         cout<<"enter item code: ";
//         cin>>item_code;
//         cout<<"enter price";
//         cin>>price;
//     }

//     void update(){
//         display();

//         cout<<"enter item-name ";
//         cin>>name;
//         cout<<"enter item code: ";
//         cin>>item_code;
//         cout<<"enter price";
//         cin>>price;
//     }

//     void display(){
//         cout<<name<<endl;
//         cout<<item_code<<endl;
//         cout<<price<<endl;
//     }
// };;

// class itemFile{
//     char filename[31];
// public:
//     itemFile(const char* name){
//         strcpy(filename,name);
//     }

//     int search_item(int item_code){
//         fstream f;
//         f.open(filename,ios::in | ios::app | ios:: binary);
//         item i;
//         while(!f.eof()){
//             f.read((char*)&i,sizeof(i));
//             if(i.item_code==item_code) break;
//         }
//         if(i.item_code ==item_code){
//             int n=(f.tellg()/sizeof(item))-1;;
//             f.close();
//             return n;}
//         f.close();
//         return 0;
//     }

//     void add_record(){
//         item i;
//         i.input();
//         int n;
//         if((n=search_item(i.item_code)==0)){
//             cout<<"Exists";return;
//         }

//         fstream f;
//         f.open(filename,ios::app | ios:: binary);
//         f.write((char*)&i,sizeof(i));
//         f.close();

//     }

//     void update_record(int itemcode){
//         int n;
//         if(n=search_item(itemcode)){
//             cout<<"exist"<<endl;return;}

//         item i;
//         fstream f;
//         f.open(filename,ios::in | ios::out | ios:: binary);
//         f.seekg(n,ios::beg);
//         f.read((char*)&i,sizeof(i));
//         i.update();
//         f.seekp(-1,ios::cur);
//         f.write((char*)&i,sizeof(i));
//         f.close();
//     }

//     void display(){
//         fstream f;
//         f.open(filename,ios::in | ios:: binary);
//         int j=0;
//         item i;
//         f.read((char*)&i,sizeof(i));
//         while(!f.eof()){
//             i.display();
//             f.read((char*)&i,sizeof(i));
//         }
//         f.close();
//     }
// };

// int main(){
//     itemFile f("item");
//     f.add_record();
//     // f.add_record();
//     // f.add_record();
//     f.update_record(345);
//     f.display();
// }

// #include <iostream>
// #include <list>
// #include<functional>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     list<int> l, l2;
//     l.push_back(3);
//     l.push_back(3000);
//     l.push_back(300);
//     l.push_back(30);
//     // l.push_back(30);
//     // l.push_back(30);
//     l2 = l;
//     // l2.sort();
//     l2.merge(l);
//     l2.sort();
//     l2.unique();
//     list<int>::reverse_iterator i;
//     auto it= find (l2.begin(),l2.end(), 30);
//     for (i = l2.rbegin(); i != (l2.rend()); i++)
//         cout << *it << endl;
// }



// int main()
// {
//     std::list<int> ilist;
//     ilist.push_back(1);
//     ilist.push_back(2);
//     ilist.push_back(3);

//     std::list<int>::iterator findIter = std::find(ilist.begin(), ilist.end(), 1);
// }

// class A{
// protected:
//     int x;
// public:
//     A(){x=10;}
//     void f2(){cout<<x;}
// };

// class B:public A{
//     int y;
// public:
//     B(){y=20;}
//     void f(){cout<<x;}
// };

// int main(){
//     B b;
//     A a=(A)b;
//     a.f2();
// }




#include<iostream>
using namespace std;

class A{
    public:
    void f1(double a){cout<<"A::f1(doule)\n";}
    virtual void f1(int a){cout<<"A::f1(int)\n";}
    void f1(char a){cout<<"A::f1(char)\n";}
    virtual void f1(int a,int c){cout<<"A::f1(int,int)\n";}
    void f2(char a,char c){cout<<"A::f2(char,char)\n";}

};


class C:public A{
    public:
    void f1(int a){cout<<"C::f1(int)\n";}
    void f1(char a){cout<<"C::f1(char)\n";}
    void f1(int a,float c){cout<<"C::f1(int,float)\n";}
    void f1(float f){cout<<"C::f1(float)\n";}
};


int main(){
    A*p;
    C c;
    p=&c ;
    c.f1(1,2);
    c.f2(1,2);
    p->f1('c');
    p->f1(1);
    p->f1(4.5);
    p->f1(1,2);
}
