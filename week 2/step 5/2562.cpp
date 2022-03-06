/*
2562 최댓값 
https://www.acmicpc.net/problem/2562


9개의 서로 다른 자연수가 주어질 때,
최댓값을 첫째줄에 출력
둘째 줄에 최댓값이 몇번쨰 수인지 출력함.

*/

#include <iostream>
using namespace std;

int main (){

    int arr[9];
    cin.tie(NULL);
    for (int i = 0; i<9; i++){
        int x;
        cin >> x;
        arr[i] = x;
    } 

    // 배열에서 최대값 찾고 인덱스 + 1저장.

    int max_index = 0, max = 0;
    for(int i =0; i< 9; i++){
        if(arr[i] > max ){
            max = arr[i];
            max_index = i+1;
    }
    }

    cout << max << '\n' << max_index << '\n';
    return 0;
    
}