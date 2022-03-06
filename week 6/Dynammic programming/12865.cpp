    /*
    12865 평범한 배낭
    https://www.acmicpc.net/problem/12865
    

    주요 틀린원인이 out of bound 였는데

    일단 basecase에서 k값은 무관하고 인덱스 끝까지 가기만 하면 된다.

    그리고 bag 선언은 0부터 N-1까지 
    */


    #include <iostream>
    #include <algorithm>

    using namespace std;
    //N  : 물품의 수
    //k  : 무게
    const int MAX_N = 101;
    const int MAX_K = 100001;

    int N,K;
    int dp[MAX_N][MAX_K];
    // [][0] : 무게 w
    // [][1] : 가치 v
    int bag[MAX_N][2];

    // n은 인덱스, k는 가방의 무게라고 생각하면 됨. 
    // 인덱스는 증가, k는 감소시키는 방향으로 나아감. 
    int f(int n, int k){
        
        //base case
        if(n==N ) return 0;

        // 연산결과 저장된거 있으면 출력
        if(dp[n][k] != -1) return dp[n][k];

        int result = f(n+1,k);

        // 가방에 물품을 한번 담으면 끝나므로 n+1로 바로 옮기기.
        if(k>= bag[n][0]) result = max(result, f(n+1, k-bag[n][0])+bag[n][1]);

        dp[n][k] = result;
        return result;

    }

    int main(){

        int w,v;
        cin >> N >> K;

        // DP 초기화
        for(int i = 0; i <= N; i++){
            for(int j = 0; j<=K; j++){
                dp[i][j] = -1;
            }
        }

        // 물품의 (무게, 가치) 순서쌍 저장.

    

        for(int i = 0 ; i < N; i++){
            cin >> w >> v;
            bag[i][0] = w;
            bag[i][1] = v;
        
        }

        cout << f(0, K) << endl;

        return 0; 

    }