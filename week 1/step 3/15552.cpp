/*
빠른 A+B 15552
https://www.acmicpc.net/problem/15552

* C++을 사용한다면 
* cin.tie(NULL)과 sync_with_stdio(false) 이용
*/

#include <iostream>
using namespace std;

int main(){

    int T;
    cin.tie(NULL);
    // c++만 쓸때, 속도를 빠르게 해줌.
    ios_base::sync_with_stdio(false);
    cin >> T;
    for(int i = 0; i < T; i++){
        int a,b;
        cin >> a >> b;
        cout << a+b << '\n';

    }
    
    return 0;

    
}
