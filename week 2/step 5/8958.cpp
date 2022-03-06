/*
8958 0x퀴즈
https://www.acmicpc.net/problem/8958

o는 문제를 맞은 것이고, x는 문제를 틀린것.

문제를 맞은 경우, 문제의 점수는 연속된 o의 개수이다.

"OOXXOXXOOO" 점수는 1+2+0+0+1+0+0+1+2+3 = 10 점.
*/

#include <iostream>
using namespace std;

int main(){

    int T,sum = 0, tmp = 0;
    cin.tie(NULL);
    cin >> T;
    // 공백 제거.
    getchar();

    // 테스트케이스마다 배열이 필요하므로
    // 배열 생성후, for문 작동.
    for(int i = 0; i < T; i++){
        char arr[80];
        cin.getline(arr,80);
        for(int i = 0; arr[i] !='\0'; i++){
            if(arr[i] == 'O'){
                tmp += 1;
                sum += tmp;  
            }
            else if(arr[i] =='X'){
                
                tmp = 0;
                sum += tmp;
            }
        }
        cout << sum << '\n';
        sum = 0, tmp =0;
        
    }
    return 0;
}