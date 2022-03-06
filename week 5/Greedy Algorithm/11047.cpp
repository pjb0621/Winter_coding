/*
동전 0 11047 
그리디 알고리즘 구현 연습

https://www.acmicpc.net/problem/11047
*/


#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n,k, cnt = 0;
    int x;

    // 1. 동전 종류와 가치합 입력 
    cin >> n >> k ;

    // 2. 배열 선언후 동전 가치 담기.
    vector <int> coin(n);

    for(int i = 0; i < n; i++){
        cin >> x;
        coin[i] = x;
    }

    // 3. 동전의 최소 개수를 출력하기.
    // 인덱스 순회해서 k와 가장 가까운 원소 찾기
    // k - coin[j] 하고 cnt ++
    // k가 0 이 될때 까지 반복.
    int j;
    while(k != 0){
        for(j = n-1; j >= 0; j--){
            if(k >= coin[j]) break;
        }
        
        cnt ++;
        k = k - coin[j];
    }

    cout << cnt << endl;
    return 0;

}


