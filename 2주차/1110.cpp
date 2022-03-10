#include <iostream>
using namespace std;

int NewNum(int n)
{
    return (n%10)*10 + ((n/10)+n%10)%10;
}

int main(void)
{
    int n, a, i = 0;
    cin>>n;

    a = n;

    while(NewNum(a) != n)
    {
        a = NewNum(a);
        i++;
    }

    cout<<i+1<<endl;

    return 0;
}