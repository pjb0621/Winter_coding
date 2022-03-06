/*
1330 두 수 비교하기
https://www.acmicpc.net/problem/1330
*/

#include <iostream>
using namespace std;

int main(){

    int a,b;
    cin >> a >> b;
    
    if(a>b) cout << '>' << '\n';
    else if(a == b) cout << "==" << '\n';
    else if(a < b) cout << '<' << '\n';

    return 0;
}