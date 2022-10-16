/*


*/

#include <iostream>
#include <vector>
using namespace std;

int dp[15][15];

int apart(int a, int b){

    if(b==1){
        dp[a][b] = 1;
        return dp[a][b];
    }
    if(dp[a][b] != -1) return dp[a][b];

    dp[a][b] = apart(a,b-1) + apart(a-1,b);
    return dp[a][b];
    
}


int main(){

    int T;
    cin >> T;
    int test[T][2];
    // test case 저장하기
    for(int i = 0; i < T; i++){
        int k, n;
        cin >> k >> n;
        test[i][0] = k;
        test[i][1] = n;
    }

    for(int i = 0; i < T; i++){

 
        // 테스트케이스 별 초기화
        for(int j = 0; j < 15; j++){
            for(int k = 0; k < 15; k++){
                dp[j][k] = -1;
            }
        }

        // 0층의 1호부터 b호까지 인원수 채우기
        for(int j = 1; j <= test[i][1]; j++){
            dp[0][j] = j;
        }

        // 해당 k층 n호의 인원수 출력
        cout << apart(test[i][0], test[i][1]) << endl;  
    }

    return 0;


}