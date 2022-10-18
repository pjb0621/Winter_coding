/*
수 정렬하기
수의 개수가 최대 10,000,000 이므로
어떤 정렬을 할지 생각해보자.

정렬 반씩 쪼개서 보는것도 나쁘지 않을듯 하다
그냥 정렬은 n^2이라서 

버블정렬은 메모리 초과로 풀리지가 않는다.

이참에 딴건 몰라도 merge sort 하나만큼은 제대로 익혀보고 넘어가자.
손코딩 해야할듯..
*/

#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int count[10001];
    int n, least, index;
    cin >> n;
    
    for(int i = 0; i < 10001; i++){
        count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        // 입력되는 수가 1~10000인지 체크하고,
        // 그에 맞춰 인덱스에서 값을 증가시킴.
        cin >> index;
        count[index]++;
    }

    for(int i = 1; i < 10001; i++){
        int iter = count[i];
        if(iter != 0){
            for(int j = 0; j<iter; j++){
                cout << i << '\n';
            }
        }
    }

}


    /**
    // 선택정렬
    // 1. 인덱스 0 부터 n-1 까지 반복하자.
    for(int i = 0; i < n-1; i++){

        // 초기 최솟값은 첫번째 인덱스
        least = i;

        // 2. i번째 인덱스(출발점) 부터 마지막 인덱스까지 최솟값을 찾는다
        // i+1번째부터 시작해서 최솟값과 비교함
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[least]) least = j;
        }

        // 3. 최솟값이 바뀌면 swap
        if(least != i){
            tmp = arr[i];
            arr[i] = arr[least];
            arr[least] = tmp;
        }

    }
    */