/*
1463 1로 만들기. 블로그 답지 버전
https://blog.naver.com/kks227/220777103650

내가 어려워 했던 점이
점화식을
min( f(n/3)+1, f(n/2)+1, f(n-1)+1 )을 구현할떄
3개를 어떻게 비교해야할지 몰랐음.

또한 마지막에 출력을 func(N) 해야하는데
아직 생성되지도 않은 dp[N]을 출력하려 해서 오류도 발생함. 

블로그에 있는 코드를 내 방식으로 구현해봄.

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> dp;

int func(int n){

    // base case 
    if(n==1) return 0;

    // 계산 결과가 존재 한다면 그 값 리턴

    if(dp[n] != -1) return dp[n];

    // 계산 결과가 없다면 새롭게 dp[n]에 저장
    // f(n-1) + 1 을 먼저 계산하고
    // 3의 배수, 2의배수인 경우에서 최소값을 결과(tmp)에 저장.

    int result = func(n-1) + 1;
    if(n%3==0) result = min(result, func(n/3) + 1 );
    if(n%2==0) result = min(result, func(n/2) +1 );

    dp[n] = result;
    //dp에 저장해두더라도 연산결과는 처음에 내놔야힘.
    return result;


}

int main(){

    int N;
    cin >> N;
    dp.resize(N+1, -1);
    cout << func(N) << '\n';
    return 0;
}