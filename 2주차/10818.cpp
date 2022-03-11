#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin>>N;

    int arr[N], min, max;

    for(int i = 0; i<N; i++) cin>>arr[i];
    min = arr[0]; max = arr[0];

    for(int i = 0; i<N; i++)
    {
        if(arr[i]<min) min = arr[i];
        if(arr[i]>max) max = arr[i];
    }

    cout<<min<<' '<<max<<endl;

    return 0;
}