/*
10870 피보나치 수
https://www.acmicpc.net/problem/10870
*/


#include <iostream>
using namespace std;


int Fibo(int n){

    if (n==0) return 0;
    if (n==1 || n==2) return 1;
    
    while(1){
        return Fibo(n-1) + Fibo(n-2);
    }


}


int main(){
    int n;
    cin >> n;
    cout << Fibo(n) << '\n';

}