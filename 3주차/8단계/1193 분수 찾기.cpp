/*
    분수 찾기
    https://www.acmicpc.net/problem/1193
*/

#include <iostream>

using namespace std;

int main(){
    int n=1, X=0;
    cin >> X;
    while(X>n){
        X=X-n;
        n++;
    }
    if(n%2==0){
        cout << X << "/" << n+1-X << endl;
    }
    else{
        cout << n+1-X << "/" << X << endl;
    }
    return 0;
}