/*
9465 스티커
https://www.acmicpc.net/problem/9465


점화식을 어떻게 세우고 dp 스럽게 푸는지에 대한
힌트를 받고 시작함

sticker (c, status)
c는 어디 열부터 최대가치를 생각하겠다는 것이고
status는 0이면 왼쪽열에 떼어낸 스티커가 없다
1은 왼쪽 위가  선택
2는 왼쪽 아래가 선택함.


dp를 1차원배열로만 선언해서 풀어보고자 함. 

--> 안되서 dp에 행부분에 status를 담는 2차원 배열로 했는데 바로 된다..
이유가 뭘까?

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[3][100000];
int arr[2][100000];
int N;

int sticker(int c, int status){

    // base case
    // N까지 도달하면 종료.

    if(c==N) return 0;

    // 연산 결과가 저장되어 있으면 출력

    if(dp[status][c] != -1) return dp[status][c];

    // sticker (c+1, 0)을 기본으로 해서 0번쨰 열에서 아무것도 안고른거로 시작.

    int result = sticker(c+1, 0);
    // status가 1이 아니면, 아래를 선택 or 아무것도 아니므로 다음열은 무조건 위의꺼를 골라야하므로 status 1
    // 왼쪽 열에서 선택한 스티커 점수를 더함 
    if(status != 1) result = max(result, sticker(c+1,1) + arr[0][c]);
    if(status != 2) result = max(result, sticker(c+1,2) + arr[1][c]);

    dp[status][c] = result;
    return result;

}

int main(){
    // TestCase의 개수
    // n : 열의 개수
    int TestCase;
    

    cin >> TestCase;

    for (int i = 0;  i < TestCase; i++){
        
        // dp 크기를 n+1로 재조정함. 
        cin >> N;
        fill(&dp[0][0], &dp[2][100000],-1);


        // 2n개의 스티커를 arr에 담는다.
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                int x;
                cin >> x;
                arr[i][j] = x;
            }
        }

        cout << sticker(0,0) << '\n';
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                
                arr[i][j] = -1;
            }
        }

        
    }

    return 0;
}