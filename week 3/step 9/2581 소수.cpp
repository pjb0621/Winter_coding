/*
2581 소수
https://www.acmicpc.net/problem/2581
*/

// 함수를 활용하고자 함.
#include <iostream>
using namespace std;


bool isPrime(int number){
    if(number == 1 || number == 0) return false;

    for(int i = 2; i<number; i++){
        if(number % i == 0) return false;
    }
    return true;
}

int main(){

    int M, N;
    cin >> M >> N;
    // Q. M부터 N까지의 수를 배열에 넣으려하면
    // 배열의 크기는 N-M+1보다 크게 해야하나?
    // 문자열은 확실한데..
    int *arr = new int[N-M+1];
    int sum = 0, min ;

    // M이상 N이하 자연수중 소수인것들을 골라야함.
    // 배열에 저장하려 했는데 귀찮아서 그냥 없이함
    for (int i = M; i <= N; i++){
        if(isPrime(i)){
            sum += i;
            if(min == 0) min = i;
            else if(i < min) min = i;
        }
    }
    
    if(sum != 0){
        cout << sum << '\n';
        cout << min << '\n';
        
    }else{
        cout << -1 << '\n';
        return 0;

    }

    return 0;
}