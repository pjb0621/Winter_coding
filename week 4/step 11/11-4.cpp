/*
1018 체스판 다시 칠하기
https://www.acmicpc.net/problem/1018
*/

// 브루트 포스 이용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    // n,m은 8보다 크거나 같고, 최대 50이다. 
    int n,m;
    cin >> m >> n;

    // 가로 m 세로 n인 배열을 만들고
    // 입력받은 값을 배열에 넣는다. 
    char arr [51][51];

    for (int i = 0; i < m; i++){

        for(int j = 0; j < n ; j++){
            char x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    

    int  cnt = 0 , min_value = 2500, tmp;

    // m x n 체스판에서 8 x 8 보드를 몇개 만들 수 있는가를 카운트.
    // 그리고 그 경우마다 cnt를 계산해서 최소값을 얻어냄.
    for(int i =0; i <= m-8; i++){
        for(int j = 0; j <= n-8; j++){

            // 8 x 8 체크보드에서 수정 횟수를 구하는 과정
            // 비교 기준은 첫칸이 W인 경우로 함.
            // CNT와 64-CNT중 최소값을 TMP로 취하고
            // TMP와 전체 MIN값 비교.
            for(int a = i; a < i+8; a++){
                for(int b = j; b<j+8; b++){

                    
                        if((a+b)%2 == 0 && arr[a][b] == 'B') cnt ++;
                        if((a+b)%2 == 1 && arr[a][b] == 'W') cnt ++;
                        
                        
                    }

                }
            tmp = min(cnt, 64-cnt);
            if(min_value > tmp) min_value = tmp;
            cnt = 0;
            }
           
        }

        cout << min_value << endl;
        
        return 0;
    }



