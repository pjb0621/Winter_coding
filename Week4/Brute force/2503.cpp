/*
    숫자 야구
    https://www.acmicpc.net/problem/2503
*/

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans=0, strk=0, ball=0;
    int arr[9][9][9]={0,};
    int count=0;
    for(int i=0;i<N;i++){
        cin >> ans >> strk >> ball;
        for(int a=0;a<9;a++){
            for(int b=0;b<9;b++){
                for(int c=0;c<9;c++){
                    int strkA=0, ballA=0;
                    if(a==b || b==c || c==a) arr[a][b][c]=1;
                    if(ans%10==c+1) strkA++;
                    else if(ans%10==a+1 || ans%10==b+1) ballA++;
                    if((ans/10)%10==b+1) strkA++;
                    else if((ans/10)%10==a+1 || (ans/10)%10==c+1) ballA++;
                    if(ans/100==a+1) strkA++;
                    else if(ans/100==b+1 || ans/100==c+1) ballA++;
                    if(ball!=ballA || strk!=strkA) arr[a][b][c]=1;
                }
            }
        }
    }
    for(int a=0;a<9;a++){
        for(int b=0;b<9;b++){
            for(int c=0;c<9;c++){
                if(a==b || b==c || c==a) continue;
                else if(arr[a][b][c]==0) count++;
            }
        }
    }
    cout << count << '\n';
    return 0;
}