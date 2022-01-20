// 분수찾기 https://www.acmicpc.net/problem/1193

#include <iostream>
using namespace std;

int main(){
    int N, i=0, n=1, k;
    cin>>N;

    while(N>i){
        i += n;
        n++;
    }
    k = i-N+1;

    if(n%2==0) cout<<k<<"/"<<n-k;
    else cout<<n-k<<"/"<<k;
}