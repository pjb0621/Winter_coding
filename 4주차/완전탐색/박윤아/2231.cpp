// 분해합 https://www.acmicpc.net/problem/2231

#include <iostream>
#include <vector>
using namespace std;

int generate(int N){
    int sum=N;
    while(N!=0){
        sum+=N%10;
        N = N/10;
    }
    return sum;
}

int main(){
    int N, min;
    cin>>N;
    min=N;

    for(int i=N; i>0; i--){
        if(generate(i)==N){
            if(i<min) min=i;
        }
    }

    if(min==N) cout<<0;
    else cout<<min;
}