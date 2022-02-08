/*
    1로 만들기
    https://www.acmicpc.net/problem/1463
*/

#include <iostream>

using namespace std;

int oneone(int X);

int main() {
    int X;
    cin >> X;
    oneone(X);
}

int oneone(int X){
    if(X==1) return 0;
    else{
        if(X%6==0) {
            int min=0;
            min=oneone(X/3)+1;
            if(oneone(X/2)<oneone(X/3)) min=oneone(X/2)+1;
        }
    }
}