// 피보나치 수 5 https://www.acmicpc.net/problem/10870

#include <iostream>
using namespace std;

int f(int N){
    if(N==0) return 0;
    else if(N==1) return 1;
    return f(N-1)+f(N-2);
}

int main(){
    int N;
    cin>>N;
    cout<<f(N);
}