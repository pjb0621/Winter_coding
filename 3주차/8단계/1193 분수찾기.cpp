/*
1193 분수 찾기
https://www.acmicpc.net/problem/1193
*/

#include <iostream>
using namespace std;

int main(){
    
    int N,i,j;
    cin >> N;

    if (N==1){
        cout << 1 << '/' << 1 << endl;
        return 0;
    }
    int n = 1;
    int status = 1;
    // 1. Sum(n) < N <= Sum(n+1)에 해당하는 n 값을 찾는다.
    while(status){
        if ((n*(n+1)/2) < N && N <= ((n+1)*(n+2)/2)){
            status = 0;
            continue;
        }
        n += 1;
    }

    int m = (n+1);

    if(m%2 == 1){
        i = (N - (n*(n+1)/2) );
        j = m+1-i;
        
    }
    else if(m%2 == 0){
        j =( N - (n*(n+1)/2));
        i = m+1-j;
        
    }

    cout << j << '/' << i << endl;

    return 0;


}