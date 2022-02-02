/*
11653 소인수 분해
https://www.acmicpc.net/problem/11653
*/

#include <iostream>
using namespace std;
/*
시간초과로 인하여 다시 작성
bool isPrime(int num){

    if(num == 0 || num == 1) return false;
    for(int i = 2; i * i<= num ; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int prime_fac(int num){
    if(num == 1|| num == 0) return 0;

    for(int i = 2; i <= num; i++){
        if(isPrime(i) && num % i == 0){
            cout << i << endl;
            return prime_fac(num/i);
        }
    } 
}

int main(){

    int N;
    cin >> N;
    
    prime_fac(N);
    return 0;
}
*/

bool isPrime(int num){

    if(num == 0 || num == 1) return false;
    for(int i = 2; i * i<= num ; i++){
        if(num % i == 0) return false;
    }
    return true;
}

// 백준 질문을 통해서
// 소수를 구하는 순간 복잡도가 크게 증가하니까
// 소수임을 판단하지 않고 그냥 인수만 구하는데 집중
// 특히, N이 계속해서 갱신되면 소수임을 판단하지 않아도 됨
int main(){
    int N;
    cin >> N;

    int* arr = new int[N];

    if (N==1) return 0;

    
            
    for(int i = 2; i <= N; i++){
                
        while(N % i == 0){
            
            cout << i << '\n';
            N /= i; 
        }
    }
}

    
