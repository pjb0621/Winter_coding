/*
    스티커
    https://www.acmicpc.net/problem/9465
*/

#include <iostream>
#include <algorithm>

using namespace std;
int sticker[2][100005];
int result[2][100005];
void fill(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        for(int j=0;j<2;j++){
            for(int k=0;k<n;k++){
                cin >> sticker[j][k];
                result[j][k]=0;
            }
        }
        fill(n);
        int sum=0;
        sum=max(result[0][0], result[1][0]);
        cout << sum << '\n';
    }
    return 0;
}

void fill(int n){
    result[0][n]=0;
    result[1][n]=0;
    result[0][n-1]=sticker[0][n-1];
    result[1][n-1]=sticker[1][n-1];
    for(int i=n-2;i>=0;i--){
        result[0][i]=max(sticker[0][i]+result[1][i+1], sticker[0][i]+result[1][i+2]);
        result[1][i]=max(sticker[1][i]+result[0][i+1], sticker[1][i]+result[0][i+2]);
    }
}