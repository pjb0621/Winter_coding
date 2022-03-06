/*
9184 신나는 함수 실행
https://www.acmicpc.net/problem/9184


바로 틀렸습니다만 뜬다..

진수랑 같이봄
틀린 이유 : while 문이 참이 되는 조건에 탈출 조건을 서놓음.
배운거 : result 임시변수로 dp에 저장안하고 바로 해도 된다. 

+) scanf로 바꾸니까 엄청 발라짐. 
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;
int dp[102][102][102];

int f(int a,int b,int c){

    if(a<=0 || b<=0 || c<=0) return 1;

    if(a>20 || b>20 || c>20){
        dp[a][b][c] = f(20,20,20);
        return dp[a][b][c];
    }

    if(dp[a][b][c] != -1) return dp[a][b][c];

    if(a<b && b<c) dp[a][b][c] = f(a,b,c-1) + f(a,b-1,c-1) - f(a,b-1,c);
    else dp[a][b][c] = f(a-1, b, c) + f(a-1,b-1,c) + f(a-1,b,c-1) - f(a-1,b-1,c-1);
    
    return dp[a][b][c];
}


int main(){
    int a,b,c;
    memset(dp,-1,sizeof(dp));
    while(true){
        
        
        scanf("%d %d %d", &a, &b, &c);
        if(a== -1 && b==-1 && c== -1) break;
        printf("w(%d, %d, %d) = %d\n", a,b,c,f(a,b,c));
    }

    return 0;
}