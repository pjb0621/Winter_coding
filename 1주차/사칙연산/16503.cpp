#include <iostream>
#include <cmath>
using namespace std;

int cal(int n1, int n2, char c)
{
    if(c == '+') return n1+n2;
    if(c == '-') return n1-n2;
    if(c == '*') return n1*n2;
    if(c == '/') return n1/n2;
}

int main(void)
{
    long n[3];
    char c[2];

    cin>>n[0]>>c[0]>>n[1]>>c[1]>>n[2];

    int n1, n2;

    n1 = cal(cal(n[0], n[1], c[0]), n[2], c[1]);
    n2 = cal(n[0], cal(n[1], n[2], c[1]), c[0]);

    cout<<min(n1, n2)<<endl;
    cout<<max(n1, n2)<<endl;

    return 0;
}