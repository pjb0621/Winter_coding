/*
2442 별찍기-5
https://www.acmicpc.net/problem/2442
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=n-i-1; j>0; j--) cout << " ";
        for(int k=0; k<2*i+1; k++ ) cout <<"*";
        cout << '\n';

    }
    return 0;
}