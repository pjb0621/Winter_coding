/*
01 타일 1904번
https://www.acmicpc.net/problem/1904
*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> dp;

int f(int n){

    if (n==1) return 1;
    if (n==2) return 2;

    if(dp[n] != -1) return dp[n];

    int result = f(n-1)+ f(n-2);

    dp[n] = result % 15746;

    return dp[n];


}

int main(){
    int N;
    cin >> N;
    dp.resize(N+1, -1);
    cout << f(N) << endl;

    return 0;
}