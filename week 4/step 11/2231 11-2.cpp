/*
2231 분해합
https://www.acmicpc.net/problem/2231
*/

#include <iostream>
using namespace std;


// 분해합을 구해서 생성자인지 확인하는 함수
// 생성자이면 True 
// M에서 분해합을 구해서 생성자인지 판단함.

int decompose(int M){
    
    int tmp = M;

    if (M < 10) return M + M;

    else if ( M >= 10){
        while(M != 0){
            tmp += M % 10;
            M /= 10;
        }

        return tmp;
    }
}

int main(){

    int N;
    cin>> N;
    
    int min = N+1;
    for(int i = 0; i < N; i++){
        if(decompose(i) == N && min > i){
            min = i;
        }
    }

    if(min == N+1) cout<< 0 << endl;
    else cout << min << endl;

    return 0;
}