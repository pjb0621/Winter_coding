/* https://www.acmicpc.net/problem/2156
효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 
효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.
포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 
1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 
효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 
예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 
첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

입력
첫째 줄에 포도주 잔의 개수 n이 주어진다. (1 ≤ n ≤ 10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 
순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.

출력
첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, tmp, Max;
    cin >> N;
    int *value = new int[N+1];
    int **dp = new int*[N+1];
    for(int i = 1; i<=N; i++) {
        cin >> value[i];
        dp[i] = new int[2]; // 0은 1번 연속, 1은 2번 연속일 때 최적해 2는 선택안할 때 최적해
    }
    if(N==1) {
        cout << value[1];
        return 0;
    }
    if(N==2) {
        cout << value[1]+value[2];
        return 0;
    }
    dp[1][0] = value[1];
    dp[1][1] = value[1];
    dp[1][2] = 0;
    dp[2][0] = value[2];
    dp[2][1] = value[1]+value[2];
    dp[2][2] = value[1];
    Max = dp[2][1];
    for(int i = 3; i<=N; i++) {
        dp[i][0] = value[i] + dp[i-1][2];
        dp[i][1] = value[i] + dp[i-1][0];
        dp[i][2] = Max;
        if(Max < max(max(dp[i][0], dp[i][1]),dp[i][2])) {
            Max = max(max(dp[i][0], dp[i][1]),dp[i][2]);
        }
    }
    cout << Max; // N-2는 절대 최적해가 아님이 보장되니까, N-1과 N에서 최대 탐색 -> 이게 개소리였죠? 병신 ㅋㅋ
}
