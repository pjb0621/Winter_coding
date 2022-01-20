// 벌집 https://www.acmicpc.net/problem/2292

#include <iostream>
using namespace std;

int main(){
    int N, i=1, n=1;
    cin>>N;

    while(N>i){
        i += 6*n;
        n++;
    }
    cout<<n;
}