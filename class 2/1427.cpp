/*
문자열 배열로 먼저 받고,
원소 하나하나 쪼개서 int 배열로 옮긴다음,

최대값 찾고 바꾸는 선택정렬 이용하자.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    int num;
    cin >> num;

    int arr[100];
    int N = 0;
    // 각 자릿수 배열에 넣기
    while(num != 0){
        arr[N++] = num % 10;
        num /= 10;
    }


    // 선택정렬
    int max = -1, max_idx;
    for(int i = 0; i < N-1; i++ ){
        max = arr[i];
        for(int j = i; j < N; j++){
            if(max <= arr[j]){
                max = arr[j];
                max_idx = j;
            }
        }

        if(max != arr[i]){
            int temp = arr[i];
            arr[i] = max;
            arr[max_idx] = temp;
        }
    }

    for(int i = 0; i < N; i++) printf("%d", arr[i]);
}