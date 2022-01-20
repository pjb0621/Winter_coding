// 상수 https://www.acmicpc.net/problem/2908

// string, reverse 이용한 풀이

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string A, B;
    int a, b;
    cin>>A>>B;
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    a = stoi(A);
    b = stoi(B);

    if(a>b) cout<<a;
    else cout<<b;
}