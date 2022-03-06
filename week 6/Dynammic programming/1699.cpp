    /*
    1669 제곱수의 합

    https://www.acmicpc.net/problem/1699

    */

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <cmath>



    using namespace std;
    const int MAX_N = 100001;
    
    const int MAX_I = 318;
    int dp[MAX_I][MAX_N];
    int index; 

    int f(int i, int n){

        // base case
        if(i == 1) return n/i;
        // 연산한 적이 있다면 결과 도출.
        if(dp[i][n] != -1) return dp[i][n];

        
        int result = f(i-1, n);

        // 특수 케이스. 

        if(n >= i*i) result = min(result,f(i,n-i*i)+1);

        dp[i][n] = result;
        return result;

    }


    int main(){

        int N, tmp = 1;
        cin >> N;

        while(tmp*tmp <= N){
            tmp++;
        }

        index = tmp;
        

        for(int i = 0; i <= index; i++){
            for(int j = 0; j <= N; j++){
                dp[i][j] = -1;
            }
        }


        cout << f(index, N) << endl;


        
    }