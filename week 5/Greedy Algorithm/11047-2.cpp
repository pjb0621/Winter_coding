/* 
11047 동전 0 

k와 cnt 접근을 수식적으로 하면 시간 복잡도를 크게 줄일 수 있다.

cnt += k/coin[i];
k  = k %coint[i];

예를 들어 36을 20 10 5 1 로 접근할때
36 % 20 = 16이 되고
동전 20을 한번 쓰는게 36 / 20으로 충분히 커버 가능하다.

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector <int> coin(n);

    for(int i = 0; i<n; i++){
        int x;
        cin>> x;
        coin[i] = x;

    }
    
    int j, cnt = 0;
    while(k!=0){
        for(j= n-1; j>=0; j--){
            
            // k가 coin[j] 와 같은 경우도 고려!
            if(coin[j] <= k) break; 
        }

        cnt += k / coin[j];
        k = k % coin[j];
    }

    cout << cnt << endl;
}