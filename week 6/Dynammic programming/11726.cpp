/*
2xn 타일링 11726번
https://www.acmicpc.net/problem/11726

dp[n] 이런식으로 저장할때 실수하는게,

벡터를 쓰면 dp.resize(n+1, -1); 하면 되는데
for문으로 채울때는 i < n 해서 실수가 많이 나옴.

그니까 n까지 다 채우기.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int tile(int n){

    // base case
    if (n==1) return 1;
    if (n==2) return 2;

    // 연산한 적이 있으면 dp에서 return
    if(dp[n] != -1) return dp[n];

    // 저장하기
    int result = tile(n-1) + tile(n-2);
    dp[n] = result % 10007;
    return dp[n];


}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i <= N; i++){
        dp[i] = -1;
    }

    cout << tile(N) << endl;

    return 0;

}