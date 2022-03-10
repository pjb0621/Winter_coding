#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n[3], k, a = 0;

    for(int i = 0; i<3; i++) cin>>n[i];

    if(n[0] == n[1])
    {
        k = n[0];
        a++;
    }

    if(n[0] == n[2])
    {
        k = n[0];
        a++;
    }

    if(n[1] == n[2])
    {
        k = n[1];
        a++;
    }

    if(a == 0) cout<<max(max(n[0], n[1]), n[2])*100<<endl;
    else if(a == 1) cout<<1000+k*100<<endl;
    else cout<<10000+k*1000<<endl;

    return 0;
}