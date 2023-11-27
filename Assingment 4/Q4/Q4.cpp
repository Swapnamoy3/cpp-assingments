/*
Design a STRING class, which will have the initialization facility similar to array
class. Provide support for
• Assigning one object for another,
• Two string can be concatenated using + operator,
• Two strings can be compared using the relational operators.
*/

/*
- initialize with an  string ex: a1="hello"
- initialize with another oject
- concat
- compared using relatational opreator

*/

#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
// using namespace std;
class STRING
{
    char str[100];

public:
    STRING(const char s[] = "")
    {
        int i = 0;
        while (s[i] != '\0')
        {
            str[i] = s[i];
            // cout<<s[i];
            i++;
        }
        str[i] = '\0';
    }

    STRING operator+(STRING &s)
    {
        STRING res;

        int i = 0;
        while (this->str[i] != '\0')
        {
            i++;
        }

        res = *(this);

        int j = 0;
        while (s.str[j] != '\0')
        {
            res.str[i + j] = s.str[j];
            j++;
        }

        res.str[i + j] = '\0';

        return res;
    }

    int operator==(STRING &s)
    {
        int l1 = 0, l2 = 0;
        while (str[l1] != '\0')
            l1++;
        while (s.str[l2] != '\0')
            l2++;

        if (l1 != l2)
            return 0;

        for (int i = 0; i < l1; i++)
        {
            if (str[i] != s.str[i])
                return 0;
        }

        return 1;
    }

    int operator<=(STRING &s)
    {
        int i = 0;
        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] < s.str[i])
                return 1;

            else if (str[i] > s.str[i])
                return 0;

            i++;
        }

        int l1 = 0, l2 = 0;
        while (str[l1] != '\0')
            l1++;
        while (s.str[l2] != '\0')
            l2++;

        if (l1 == l2 || l2 > l1)
            return 1;
        else
            return 0;
    }

    int operator>=(STRING &s)
    {
        int i = 0;
        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] > s.str[i])
                return 1;

            else if (str[i] < s.str[i])
                return 0;

            i++;
        }

        int l1 = 0, l2 = 0;
        while (str[l1] != '\0')
            l1++;
        while (s.str[l2] != '\0')
            l2++;

        if (l1 == l2 || l2 < l1)
            return 1;
        else
            return 0;
    }

    int operator<(STRING &s)
    {
        int i = 0;
        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] < s.str[i])
                return 1;

            else if (str[i] > s.str[i])
                return 0;

            i++;
        }

        int l1 = 0, l2 = 0;
        while (str[l1] != '\0')
            l1++;
        while (s.str[l2] != '\0')
            l2++;

        if (l2 > l1)
            return 1;
        else
            return 0;
    }

    int operator>(STRING &s)
    {
        int i = 0;
        while (str[i] != '\0' && s.str[i] != '\0')
        {
            if (str[i] > s.str[i])
                return 1;

            else if (str[i] < s.str[i])
                return 0;

            i++;
        }

        int l1 = 0, l2 = 0;
        while (str[l1] != '\0')
            l1++;
        while (s.str[l2] != '\0')
            l2++;

        if (l2 < l1)
            return 1;
        else
            return 0;
    }

    void print()
    {
        cout << str;
    }
};

int main()
{
    const char str[100] = "swapnamoy";

    STRING s = str;
    cout<<"STRING s: ";
    s.print();
    cout<<endl;

    STRING s1 = "swapnamoya";
    cout<<"STRING s1: ";
    s1.print();
    cout << endl;

    STRING res = s + s1;
    cout<<"STRING s1: ";
    res.print();
    cout << endl;


    cout<<"Cheacking relationsl operators: \n";
    s.print();cout<<" < ";s1.print();
    cout <<" "<< (s < s1)<<endl;

    s.print();cout<<" > ";s1.print();
    cout <<" "<< (s > s1)<<endl;

    s.print();cout<<" <= ";s1.print();
    cout <<" "<< (s <= s1)<<endl;

    s.print();cout<<" >= ";s1.print();
    cout <<" "<< (s >= s1)<<endl;
}