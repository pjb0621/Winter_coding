/*
피보나치 함수 1003
https://www.acmicpc.net/step/16

*/

#include <iostream>
#include <vector>
using namespace std;


vector <int> dp;

int fibo(int n){

    if(n < 0) return 1;

    
    if(n==0) return 0;
    
    if(n==1) return 1;
    
    if(dp[n] != -1) return dp[n];

    int result = fibo(n-1) + fibo(n-2);

    dp[n] = result;
    return result;
}

int main(){
    
    int T;
    cin >> T;

    // 피보나치 수열에서 0과 1이 호출되는 횟수또한 피보나치 수열을 따르는데
    // 0의 경우 f(n-1) , 1은 f(n) 과 같다.
    for(int i = 0; i<T; i++){
        int x;
        cin>> x;
        dp.resize(x+1,-1);
        cout << fibo(x-1) << " " << fibo(x) << endl;
    }

    return 0;
} 