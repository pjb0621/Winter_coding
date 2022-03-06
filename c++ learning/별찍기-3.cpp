/*
2440 별 찍기 - 3
https://www.acmicpc.net/problem/2440
*/

#include <iostream>
using namespace std;

int main(){
    int N,k;
    cin >> N;

    // N번째 행까지.
    for (int i = 0 ; i < N; i++){
        //별 = 5칸.
        //별 5개부터 1개까지 줄이기. 
        for(int j = N-i; j >= 1; j--) cout << "*";
     
        cout << '\n';
    }
    return 0;
}