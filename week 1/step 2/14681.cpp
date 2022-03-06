/*
14681 사분면 고르기
https://www.acmicpc.net/problem/14681
*/

#include <iostream>
using namespace std;

int main(){

    int x,y;
    cin >> x >> y;

    // 사분면 구분.

    if ( x>0 && y>0) cout << 1 << endl;
    if ( x<0 && y>0) cout << 2 << endl;
    if ( x<0 && y<0) cout << 3 << endl;
    if ( x>0 && y<0) cout << 4 << endl;

    return 0;
}