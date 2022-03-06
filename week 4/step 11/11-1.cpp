/*
2798 블랙잭
https://www.acmicpc.net/problem/2798
*/

#include <iostream>
using namespace std;

// 카드의 개수 N과 M이 주어진다.
// M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력
// N의 입력범위는 100이므로 브루트포스를 이용한다.
int main(){

    int N,M, x;
    cin >> N >> M;

    // N의 최대값 + 1로 사이즈
    // 배열에 넣는다
    int arr[100];
    for(int i=0; i<N; i++){
        cin >> x;
        arr[i] = x;
    }

    // 3장의 합을 한번에 구한다. 
    // 3중 반복문을 이용해도 연산횟수는 100만 이하이다.
    int max = 0, tmp;

    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            
            for(int k = 0 ; k < N; k++){
                // i,j,k가 달라야 한다.
                if(i!= j && j!= k && k!= i){
                    tmp = arr[i] + arr[j] + arr[k];
                    if(tmp > max && tmp <= M) max = tmp;

                }
            
            }
        
    }
    } 

    cout << max << endl;

    return 0;


}