#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a)
{
    long long sum = 0, n;

    for(int i = 0; i<a.size(); i++)
    {
        sum += a[i];
    }

    return sum;
}

int main(void)
{
    int N, n;
    vector<int> v;

    cin>>N; 

    for(int i = 0; i<N; i++)
    {
        cin>>n;
        v.push_back(n);
    }

    cout<<"SUM : "<<sum(v)<<endl;

    return 0;
}