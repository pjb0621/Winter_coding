/*
2193 이친수
https://www.acmicpc.net/problem/2193

블로그의 힌트를봄

가장 큰 이유는 이진수의 첫자리는 일반적인 숫자 개념의 맨 뒷자리와 같음.

*/

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N;
long int dp[2][90];

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