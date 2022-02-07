/*
    동전 0
    https://www.acmicpc.net/problem/11047
*/

#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int coin[N];
    int count=0;
    //각 동전 금액 입력받기 (N개)
    for(int i=0;i<N;i++){
        cin >> coin[i];
    }
    //금액이 큰 동전부터 몫을 동전의 개수로 환산해 저장
    for(int j=N-1;j>=0;j--){
        count=count+K/coin[j];
        K=K%coin[j];
        if(K==0) break;
    }
    cout << count << '\n';
    return 0;
}