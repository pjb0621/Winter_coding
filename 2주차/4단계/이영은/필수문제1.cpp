/*
    A+B - 5
    https://www.acmicpc.net/problem/10952
*/

#include <iostream>

using namespace std;

int main() {
    int a=1, b=1;
    while(1){
        cin >> a >> b;
        if(a==0&&b==0) {
            break;
        }
        cout << a+b << endl;
    }
    return 0;
}