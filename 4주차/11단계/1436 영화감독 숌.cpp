/*
    영화감독 숌
    https://www.acmicpc.net/problem/1436
*/

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int result[N]={0,};
    int i=0;
    int j=666;
    while(result[N-1]==0){
        for(int k=1000;k<j*10;k=k*10){
            if((j%k)%(666*(k/1000))<k/1000 && (j%k)/(666*(k/1000))==1){
                result[i]=j;
                i++;
                break;
            }
        }
        j++;
    }
    cout << result[N-1] << '\n';
    return 0;
}