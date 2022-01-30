/*
    하노이 탑 이동 순서
    https://www.acmicpc.net/problem/11729
*/

#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int N, int num[]){
    int num0[3]={num[2], num[0], num[1]};
    int num1[3]={num[1], num[2], num[0]};
    if(N==1) cout << num[0] << ' ' << num[2] << '\n';
    else if(N%2==0){
        hanoi(N-1, num);
        cout << num[0] << ' ' << num[1] << '\n';
        hanoi(N-1, num0);
    }
    else if(N%2==1){
        hanoi(N-1, num);
        cout << num[0] << ' ' << num[2] << '\n';
        hanoi(N-1, num1);
    }
}

int main(){
    int N;
    cin >> N;
    cout << pow(2,N)-1 << '\n';
    int numodd[3]={1,2,3};
    int numeven[3]={1,3,2};
    if(N%2==1) hanoi(N, numodd);
    else hanoi(N, numeven);
    return 0;
}