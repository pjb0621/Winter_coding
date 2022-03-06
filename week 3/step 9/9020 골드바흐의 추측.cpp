/*
9020 골드바흐의 추측
https://www.acmicpc.net/problem/9020
*/


#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int N){
    if(N == 0 || N == 1) return false;
    for(int i = 2; i * i <= N; i++){
        if(N%i==0) return false;
    }
    return true;
}

int GoldBach(int num){

    // i가 소수임을 판단하고
    // 차도 소수면 그대로 출력하기.

    int i,j, final_i = 0, final_j = 0;
    for(int i = 2; i <= num; i++){
        j = num - i;
        if(isPrime(i) && isPrime(j)){
            //맨 처음 갱신
            if(final_i == 0){
                final_i = i;
                final_j = j;
            }
            // 소수의 차가 더 적으면 갱신
            if(abs(j-i) < abs(final_i - final_j)){
                final_i = i;
                final_j = j;
            }
        }
     }
    cout << final_i << " " << final_j << '\n';
    return 0;
}




int main(){

    int T;
    cin >> T;
    
    // 1. 테스트 케이스 만큼 입력받기
    for (int i = 0; i < T; i++){
        int x;
        cin >> x;
        GoldBach(x);
    }
    return 0;
}
