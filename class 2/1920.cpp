/*
먼저 A 배열이 주어지면 정렬을 한다.

그리고 나서 M개의 수들에 대해서 A배열에서 이분탐색을 진행한다.
만약 수가 A안에 존재한다면 1을 출력한다

만약 WHILE(lo+1 < high)에서 
구간의 길이가 1이 되면 양 끝값에서 수가 존재하는지 체크하고
없으면 0을 출력한다.


*/


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    int M[100000];
    int m;
    for(int i = 0;  i < N; i++)
        cin >> A[i];

    cin >> m;
    for(int i = 0 ; i < m; i++)
        cin >> M[i];

    
    // 정렬 -> stl을 이용하여 nlogn의 시간복잡도를 가짐.
    sort(A, A+N);

    // 이분 탐색
    int target, lo, hi,mid;
    for(int i = 0 ; i < m; i++){
        target = M[i];
        lo = 0;
        hi = N-1;

        while(lo+1 < hi){
            mid = (lo+hi)/2;
            // 가운데의 인덱스 값을 target과 비교
            if(A[mid] >= target){ // mid 값이 찾고자 하는 수보다 크면, [0, mid]으로 설정
                hi = mid;
            }
            else if(A[mid] < target){ // mid값이 찾고자 하는 수보다작으면, [mid, hi]
                lo = mid;
            }
        }

        if(A[lo] == target || A[hi] == target) cout << 1 << '\n';
        else cout << 0 << '\n';

   
    }


}