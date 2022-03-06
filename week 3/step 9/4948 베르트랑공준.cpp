/*
4948 베르트랑 공준
https://www.acmicpc.net/problem/4948
*/

#include <iostream>
using namespace std;
// 이전의 에라스토테네스의 체를 활용한다
// 다만, 여러번의 입력횟수에따라 판단하므로
// 함수를 이용한다.

// 소수임을 판정하는 함수
bool isPrime(int num){
    if(num == 0 || num == 1) return false;
    
    // sqrt(num) 이하의 소수만 판단해도 됨
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

// N+1 ~ 2N사이의 소수의 개수를 카운트하는 함수
int Prime_chk(int N){

    
    int cnt = 0;

    // N+1부터 2N까지 소수 판정
    // 다만, 에라스토테네스의 체를 활용한다면 복잡도가 줄을지도??
    // 그런데, 배열까지 써서하려면 구현힘들기도하고 역효과 날거같아서 걍함
    for (int i = N+1 ; i<= 2*N; i++){
        if(isPrime(i)) cnt ++;
    }
    
    return cnt;
    

}



int main(){

    int N;
    while (1){
        int N;
        cin >> N;
        if(N == 0) return 0;
        cout << Prime_chk(N) << '\n';
    }

    return 0;
}