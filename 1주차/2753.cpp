#include <iostream>
using namespace std;

int main(void)
{
    int n, p = 0;
    cin>>n;

    if(n%4 == 0 && n%100 != 0) p++;
    if(n%400 == 0) p++;

    cout<<p<<endl;

    return 0;
}