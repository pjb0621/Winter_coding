/*
1074번 z
https://www.acmicpc.net/problem/1074
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int r,c;
int cnt = 0;

// base case가 2 x 2 인듯.
// 

// (0) len = 2인 경우는 그냥 바로 전수 조사

// (1) 4개를 먼저 분할하고 해당 범위에 인덱스가 없다면 size 만큼 더해주고
//     다음 영역으로 넘어감.
// (2) 해당 범위내에 인덱스가 존재한다면 다시한번더 분할해서 cnt += 1 하기.



bool Is_In(int y, int x, int n){

    for(int i = y; i < y + n ; i++){
        for(int j = x ; j < x + n; j++){
            if(i == r && j == c) return true;
        }
    }

    return false;
    

}

void func (int y, int x, int len){
    

    
    if(len == 2 && Is_In(y, x, len)){
        for(int i = y; i < y + len; i++){
            for(int j = x; j < x + len; j++){
                if(i == r && j == c) return;
                else cnt += 1;
            }
        }
    }
    

    // 나누어지는 문제수 4개
    // 문제의 크기는 n/2 * n/2 
    for(int i = y; i < y + len; i += int(len/2)){
        for(int j = x; j < x + len; j += int(len/2)){
            
            // 내부에 r,c가 존재하지 않으면 skip
            if(Is_In(i,j, len/2)){
                func(i,j,len/2);
                return;
            }
            else cnt += len/2 * len/2 ;

        }
    }

}
int main(){

    int n;
    cin >> n >> r >> c;
    
    int len = pow(2,n);

    func(0 , 0, len);
    cout << cnt << endl;
 

}