#include <iostream>
using namespace std;

int main(void)
{
    int arr[42] = {0 ,}, nums[10], n = 0;

    for(int i = 0; i<10; i++) cin>>nums[i];

    for(int i = 0; i<10; i++) 
    {
        n = nums[i]%42;
        arr[n] = 1;
    }

    n = 0;

    for(int i = 0; i<42; i++)
    {
        if(arr[i] != 0) n++;
    }

    cout<<n<<endl;
}