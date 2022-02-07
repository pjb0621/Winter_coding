/*
    소수 구하기
    https://www.acmicpc.net/problem/1929
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N, M;
    cin >> M >> N;
    int lst[N]={0,};
    lst[0]=1;
    double rootN=sqrt(N);
    int gN=floor(rootN);
    for(int i=2;i<=gN;i++){
        if(lst[i-1]==0){
            for(int x=i*i;x<=N;x+=i){
                lst[x-1]=1;
            }
        }
    }
    for(int j=M;j<=N;j++){
        if(lst[j-1]==0) cout << j << "\n";
    }
    return 0;
}