/*
2443 별 찍기-6
https://www.acmicpc.net/problem/2443
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i = 0 ; i < n; i++){
        for(int k = 0; k < i; k++) cout << " ";
        for(int j = 2*(n-i) -1; j>0 ; j--) cout << "*";
        
        cout << '\n';
    }
    
    return 0;

}