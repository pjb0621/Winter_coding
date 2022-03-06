/*
1978 소수찾기
https://www.acmicpc.net/problem/1978
이번 문제는 함수를 적극적으로 활용하고자 함.
*/

#include <iostream>
using namespace std;
// 소수를 판정하는 함수
// 소수이면 true, 아니면 false를 리턴함.
bool isPrime(int number){
    
    if (number == 1 || number == 0) return false;
    
    for(int i = 2; i < number; i++){
        if(number % i == 0) return false;
    }

    return true;
}

int main(){

    int N, cnt = 0;
    cin >> N;

    int *arr = new int[N+1];
    // 동적할당을 하지 않는다면, int arr[101]로 해도 된다.

    for(int i = 0; i < N; i++){
        int x; 
        cin >> x;
        arr[i] = x;
    }

    for (int i =0; i<N; i++){
        if(isPrime(arr[i])) cnt ++;
    }

    cout <<cnt << '\n';
    return 0;


}
