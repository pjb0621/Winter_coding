#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void Judge(long* n, string str)
{
    if (str == "+")
    {
        if ((n[0]+n[1]) == n[2])
        {
            cout<<"correct"<<endl;
        } else {
            cout<<"wrong answer"<<endl;
        }
    }
    if (str == "-")
    {
        if ((n[0]-n[1]) == n[2])
        {
            cout<<"correct"<<endl;
        } else {
            cout<<"wrong answer"<<endl;
        }
    }
    if (str == "*")
    {
        if ((n[0]*n[1]) == n[2])
        {
            cout<<"correct"<<endl;
        } else {
            cout<<"wrong answer"<<endl;
        }
    }
    if (str == "/")
    {
        if ((n[0]/n[1]) == n[2])
        {
            cout<<"correct"<<endl;
        } else {
            cout<<"wrong answer"<<endl;
        }
    }
}
/*
int main(void) 
{
    int test;
    string st;
    cin>>test;

    cin.clear();
    getline(cin, st);

    for(int i = 0; i<test; i++){
        string str;
        getline(cin, str);
        istringstream ss(str);
        string stringBuffer;
        vector<string> x;
        x.clear();

        while (getline(ss, stringBuffer, ' '))
        {
            x.push_back(stringBuffer);
        }

        long n[3] = {stol(x[0]), stol(x[2]), stol(x[4])};
        string op = x[1];

        Judge(n, op);
    }
}
*/

int main(void)
{
    int test;
    cin>>test;

    for(int i = 0; i<test; i++)
    {
        long n[3];
        string c1 , c2;

        cin>>n[0]>>c1>>n[1]>>c2>>n[2];

        Judge(n, c1);
    }

    return 0;
}