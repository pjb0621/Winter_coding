/*
2739 구구단
https://www.acmicpc.net/problem/2739
*/

#include <iostream>
using namespace std;
int main(){

    int n; 
    cin >> n;
    for(int i = 1; i<=9; i++){
        int x = n * i;
        cout << n << " * "  << i << " = " << x <<'\n';

    }

    return 0;

}