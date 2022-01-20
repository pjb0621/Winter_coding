// 소수 https://www.acmicpc.net/problem/2581

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
    int M, N, sum=0, first=0;
    cin>>M>>N;
    for(int i=M; i<=N; i++){
        if(prime_checker(i)){
            sum += i;
            if(first==0) first=i;
        }
    }
    if(first==0) cout<<-1;
    else cout<<sum<<"\n"<<first;
}