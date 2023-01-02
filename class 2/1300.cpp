/*
이분 탐색으로 k번째수 를 찾기 위해서는

배열 A안에서 특정 숫자 이하로 몇개의 숫자가 존재하는지 이분탐색을 진행한다.

만약 X 이하의 숫자가 K개고, X-1이하의 숫자가 K 미만이면 X는 K번째 수가 된다 (return hi)

lo = 1 x 1
hi = n x n
while ( lo + 1< hi)

중간값 <= k  : lo = mid
중간값 > k   : hi = mid

mid 이하의 숫자 판별은
n^2 반복문으로 일단 시도 해보고..
시간 초과 걸리나 보자.





1 2 3 4
2 4 6 8
3 6 9
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    
    int lo = 1;
    int hi = k;  // 이게 왜 n*n일떄는 틀리고, k일떄 맞는건지 모르겠음.


    while(lo < hi){
        int mid = (lo+hi) / 2;
        long long count = 0;
        for(int i = 1; i <= n; i++){
            count += min(mid/i, n);
        }
        // lower bound를 구함.
        if(count < k) lo = mid + 1;
        else hi = mid;
    }


    cout << lo << endl;


    
}