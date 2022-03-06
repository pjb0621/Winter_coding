/*
1463 1로 만들기
https://www.acmicpc.net/problem/1463

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector <int> dp;

int func(int n){

    // base case 
    if(n==1) return 0;

    // 계산 결과가 존재 한다면 그 값 리턴

    if(dp[n] != -1) return dp[n];
    
    // 계산 결과가 없다면 저장함.
    if(n%3 == 0 && n%2==0) dp[n] = min({1+func(n/3), 1+func(n/2), 1+func(n-1)});
    if(n%3 != 0 && n%2==0) dp[n] = min({1+func(n/2), 1+func(n-1)});

    if(n%3 == 0 && n%2!=0) dp[n] = min({1+func(n/3), 1+func(n-1)});

    if(n%3 !=0 && n%2 !=0) dp[n] = 1+func(n-1);

    return dp[n];

    
        
    }

    // n이 3의 배수
    



int main(){

    int N;
    cin >> N;
    dp.resize(N+1, -1);

    cout<<dp[N]<<'\n';

    return 0;
}

