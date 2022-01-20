// 소수 구하기 https://www.acmicpc.net/problem/1929

#include <iostream>
#include <cmath>
using namespace std;

bool prime_checker(int n){
    if(n==1) return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    int M, N;
    cin>>M>>N;
    for(int i=M; i<=N; i++){
        if(prime_checker(i)){
            cout<<i<<"\n";
        }
    }
}