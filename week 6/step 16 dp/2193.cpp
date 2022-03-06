/*
2193 이친수
https://www.acmicpc.net/problem/2193

블로그의 힌트를봄

틀린 이유 : Pinary 함수 부를때
pinary( 0, N)을 하는데
N의 최대 범위는 90이다.
// 그래서 Pinary(0, 90) 을 부르면
dp[0][90]에 접근을 하는데 이러면 dp[90] 즉, 배열의 91번째 원소에
접근한것과 같아서 배열 크기를 91 이상으로 해야한다. 

다음에 문제 풀때는 입력값보다 +1을  해서 배열 크기를 정하는게 풀이하는데 도움을 줄거고,

구체적으로는 함수에 넣는 입력값이 dp 배열에 어떻게 저장되는지도 생각하면서 풀자!! 

*/

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N;
long int dp[2][91];

// n은 길이를 나타냄. 
// status가 이전 인덱스의 상태. 0 이면 그 자리에 0이, 1이면 1이 위치한 것. 
long int pinary(int status, int n){

    // base case 1
    if(n == 1){
        if(status == 1) return 1;
        else return 0;
    } 

    if(dp[status][n] != -1) return dp[status][n];

    // n번째 자리에 있는 숫자가 0이면 n-1 자리가 1 or 0 둘중 하나.
    // n번째 자리에 있는 숫자가 1이면 n-1 자리는 무조건 0.
    long int result = 0;
    if(status == 0) result = pinary(0, n-1) + pinary(1,n-1);
    if(status == 1) result = pinary(0, n-1);
    dp[status][n] = result;
    return result;

}

int main(){

    cin >> N;
    memset(dp,-1, sizeof(dp));

    // n번째 자리 숫자가 0 인 경우  + 1 인 경우. 
    cout << pinary(0,N) + pinary(1,N) << endl ;

    return 0;

}