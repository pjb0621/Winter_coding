/*
https://www.acmicpc.net/problem/2292
2292 벌집
*/

#include <iostream>
using namespace std;
int main(){

    int n, line = 0;
    cin >> n;


    while(1){
        if (n==1){
            cout << 1 << '\n';
            break;
        } 
        if (2 + 3 * line *(line+1) <= n && n < 2 + 3 * (line+1)* (line+2)){

            cout << line + 2 << '\n';
            break;
        }

        line ++;

    }

    return 0;

}