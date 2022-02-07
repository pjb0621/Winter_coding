/*
    분해합
    https://www.acmicpc.net/problem/2231
*/

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans=0;
    for(int i=1;i<N;i++){
        int x=i;
        int sum=x;
        while(x!=0){
            sum=sum+(x%10);
            x=x/10;
        }
        if(sum==N){
            ans=i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}