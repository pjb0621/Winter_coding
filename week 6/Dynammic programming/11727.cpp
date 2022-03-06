/*
2xn 타일링 2  11727
https://www.acmicpc.net/problem/11727

*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> dp;

int tile(int n){

    //base case
    if(n==1) return 1;
    if(n==2) return 3;

    // 연산 결과 저장되어 있으면 출력
    if(dp[n] != -1) return dp[n];

    int result = tile(n-1) + 2*tile(n-2);
    dp[n] = result % 10007;

    return dp[n];

}

int main(){

    int N;
    cin >> N;   
    
    // dp 전역벡터 초기화.
    dp.resize(N+1, -1);

    cout << tile(N) << endl;

    return 0;

}