/*
1463 1로만들기
바텀업 방식

*/

#include <vector>
#include <iostream>
using namespace std;


int main(){

    int N;
    cin>> N;
    // 10^6 + 1로 기본 설정함.
    vector <int> dp(N+1, 1000001);
    dp[1] = 0;
    for(int i = 2; i <= N; i++){
        
        int result = dp[i-1] + 1;
        if(i % 3 == 0) result = min(dp[i/3] +1, result); 

        if(i % 2 == 0) result = min(dp[i/2] + 1 ,result);
        
        dp[i] = result;
    }

    cout << dp[N] << endl;

    return 0;



}