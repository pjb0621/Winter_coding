// 분수찾기 https://www.acmicpc.net/problem/1193

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, x, n;
    cin>>N;

    x = ceil((1+sqrt(1+8*N))/2);
    n = x*(x-1)/2;

    if(x%2==0) cout<<n-N+1<<"/"<<x-(n-N+1);
    else cout<<x-(n-N+1)<<"/"<<n-N+1;
}