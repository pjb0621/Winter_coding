/*
    체스판 다시 칠하기
    https://www.acmicpc.net/problem/1018
*/

#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string board[N];
    for(int i=0;i<N;i++){
        cin >> board[i];
    }
    int count=0, min=64;
    for(int j=0;j<=N-8;j++){
        for(int k=0;k<=M-8;k++){
            count=0;
            for(int a=0;a<8;a++){
                for(int b=0;b<8;b++){
                    if((a+b)%2==0 && board[j+a][k+b]!=board[j][k]) count++;
                    else if((a+b)%2==1 && board[j+a][k+b]==board[j][k]) count++;
                }
            }
            if(count>32) count=64-count;
            if(count<min) min=count;
        }
    }
    cout << min << '\n';
    return 0;
}