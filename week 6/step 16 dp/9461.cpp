/*
파도반 수열 9461번
https://www.acmicpc.net/problem/9461
?????

이거 100 넣으면
-203165375 나오는데 어떻게 되는거냐.

사용방법은 원래 문제는 1 <= N <= 100 인데
자체적으로 피보나치 수열처럼
0부터 시작하게 만듬. 
*/

#include <iostream>
#include <vector>
using namespace std;

vector <long int> dp;

long int p(int n){

    if(n==0) return 1;

    if(n==1) return 1;
    if(n==2) return 1;

    
    if(dp[n] != -1 ) return dp[n];

    long int result = p(n-2) + p(n-3);

    dp[n] = result;

    return result;
}

int main(){
    int T;
    cin >> T;

    for(int i =0; i< T; i++){
        int x;
        cin >> x;
        dp.resize(x+1, -1);
        cout << p(x-1) << endl;
    }
    return 0;

}