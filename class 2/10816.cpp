/*
정렬
-10 -10 2 3 3 6 7 10 10 10

있는지 확인하고자 하는 수
10 9 -5 2 3 4 5 -10

10부터 돌자.

중간 값 찾기
3 (mid) < 10 -> [6 7 10 10 10]

10(mid) <= mid -> [10 10 10]


중복되는 요소가 있을대는
lower bound와 upperbound를 찾아야한다
https://splendidlolli.tistory.com/335
참고자료



계획

1) stl 이용해서 N개의 숫자카드 배열 정렬
2) 이분탐색 시작.
이때, m개의 수마다 각각
lower bound (찾고자하는 수가 처음 시작되는 인덱스)
upper bound (찾고자하는 수가 마지막에 있는 인덱스)
를 구하고 
upper - lower + 1 해서 구한다.


lower bound 찾을떄는
target <= mid : hi = mid
target > mid  : lo = mid + 1

upper bound 찾을때는

target < mid : hi = mid
target >= mid : lo = mid + 1
-> return하는건 lo -1 하면 댐. ()
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main (){
    int N,M;
    cin >> N;
    int card[N];
    for(int i = 0 ; i < N; i++)
        cin >> card[i];
    cin >> M;
    int num[M];
    for(int i = 0; i < M; i++)
        cin >> num[i];

    
    // 숫자카드 정렬
    sort(card, card+N);

    // 이분탐색
    // upper bound - lowerbound + 1 로 중복되는 횟수 체크


    for(int i = 0; i < M; i++){
        int target = num[i];
        int lo1 = 0, lo2 = 0;
        int hi1 = N, hi2 = N;
        int mid1, mid2;
        int lowerBound, upperBound;
        // lower bound
        while(lo1 < hi1){
            mid1 = (lo1+hi1)/2;

            if(target <= card[mid1] ) hi1 = mid1;
            else lo1 = mid1 +1 ;
        }

        lowerBound = lo1;

        while(lo2  < hi2){
            mid2 = (lo2+hi2)/2;

            if(target >= card[mid2]) lo2 = mid2 + 1;
            else hi2 = mid2;
        }

        upperBound = lo2-1;

       //  cout << upperBound << endl;
       //  cout << lowerBound << endl;
        cout << upperBound -lowerBound + 1 << ' ';
    }



}