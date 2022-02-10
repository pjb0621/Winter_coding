/* https://www.acmicpc.net/problem/11054

수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 
{10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)
출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다. */

#include <iostream>
#include <string>   
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,j, right1, right0;
    cin >> N;
    pair<int,int,int> tmp;
    tuple<int,int,int> **dp = new tuple<int,int,int>*[N+1]; // dp[i][0/1] = int,int => 1번째~i번째까지 봤을 때 최적해 / i번째 포함미포함(0,1)
    //int, int = 길이, 가장 오른쪽의 값
    int *nums = new int[N+1];
    for(int i = 1; i<=N; i++) {
        cin >> nums[i];
        dp[i] = new tuple<int,int,int>[2];
    }
    dp[1][0] = make_tuple(1, nums[1],  nums[1]);
    dp[1][1] = make_tuple(0, -1, -1);
    //사고 1. 수열을 증가하는 수열들의 단위로 분리한다면? -> 컷
    //사고 2. 역순으로 탐색한다면? 
    //사고 1, 2에서 억지로 i-1과의 점화식을 구하려고 한 것이 패인이었음
    //바로 전 요소에서 오름차순이 유지된다면, 점화식 관계가 성립
    //그렇지 않은 경우에는 1~i-1까지 탐색해가며 최적해를 완전탐색해야한다.
    for(int i = 2; i<=N; i++) {
        if(dp[i-1][0].first == dp[i-1][1].first) {
            dp[i][1] = (dp[i-1][0].second < dp[i-1][1].second) ? dp[i-1][0]: dp[i-1][1];
            // 수열 길이가 같다면, 가장 오른쪽 값이 작은 놈이 더 유리함
        }
        else {
            dp[i][1] = (dp[i-1][0].first > dp[i-1][1].first) ? dp[i-1][0]: dp[i-1][1];
            // 길이가 같지 않으면 수열 길이로 판단
        }
        //i번째를 포함하지 않는다면, i-1번째까지의 수열에서 최적해가 곧 i번째의 최적해임
        //이전 코드에서, isUpdated변수를 사용해서 갱신되었나 여부를 확인하였음.
        //그냥 dp[i][0]에 기본값을 not updated상황에서의 값으로 설정해주면 더 간결하게 코드가 나오겠네?
        //씨발
        dp[i][0] = make_pair(1,nums[i]);
        for (j = i - 1; j >= 1; j--)
        {
            // 현재 수열 길이랑, j의 위치를 ㅣㅂ교하면 break조건,continue조건 검토 가능
            if(j+1 <= dp[i][0].first) break;
            // j의 위치 = dp[j]에서 나올 수 있는 길이 값의 상한선
            //if( dp[j][0].first + 1 <= dp[i][0].first && dp[j][1].first + 1 <= dp[i][0].first) continue;
            // j번째에서 최적해가 갱신되지 않는다면 패쓰 => 두 차례에 걸쳐서 갱신하는 방식으로 가는게 더 깔끔할 듯.
            right0 = dp[j][0].second;
            right1 = dp[j][1].second; //바로 이전의 두 최적해에서 가장 오른쪽 값을 가져옴.
            if(nums[i] > right0 && dp[j][0].first+1 > dp[i][0].first ) { //오름차순 만족 & 길이 갱신조건 만족
                dp[i][0].first = dp[j][0].first+1;
            }
            if(nums[i] > right1 && dp[j][1].first+1 > dp[i][0].first ) { //오름차순 만족 & 길이 갱신조건 만족
                dp[i][0].first = dp[j][1].first+1;
            }
        }
        //cout << dp[i][0].first <<" "<< dp[i][0].second << " " << dp[i][1].first << " "<< dp[i][1].second<<endl;
    }
    cout << max(dp[N][0].first, dp[N][1].first);
    
    //1000개짜리 1~1000의 배열과 주어진 수열을 비교한다?
    //바로 연속되는 수열을 찾으면, 얘네는 최적해가 된다.
}
