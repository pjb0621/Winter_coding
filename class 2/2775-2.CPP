/*
koosaga님 풀이 복기
이미 아파트 층, 호의 인원수를 채워놓고 초기화 하지 않아도
되는 점을 이용함.
*/

#include <iostream>
using namespace std;

int dp[15][15];

int main(){
    int t;
    cin >> t;
    for(int i = 1; i<=14; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            for(int k = 1; k <= j ; k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    while(t--){
        int k,n;
        cin >> k >> n;
        cout << dp[k][n] << endl;
    }
}