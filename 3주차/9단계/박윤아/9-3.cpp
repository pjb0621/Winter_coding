// 소인수분해 https://www.acmicpc.net/problem/11653

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

void factorize(int N){
    int i=2;
    if(N!=1){
        while(i<=N){
            if(N%i==0 && prime_checker(i)){
                cout<<i<<"\n";
                factorize(N/i);
                break;
            }
            i++;
        }
    }
}

int main(){
    int N;
    cin>>N;
    factorize(N);
}