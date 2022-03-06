/*
10872 팩토리얼 
https://www.acmicpc.net/problem/10872
*/

#include <iostream>
using namespace std; 


int fac(int N){

    if (N == 0 || N == 1) return 1;
    while(1){
        if(N >= 2) return N * fac(N-1);
    }
}
int main(){

    int n;
    cin >> n;
    cout << fac(n) << '\n';
    return 0;
    
}