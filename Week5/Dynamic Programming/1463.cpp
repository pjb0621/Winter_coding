/*
    1로 만들기
    https://www.acmicpc.net/problem/1463
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005]={0,};
int oneone(int X);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;
    for(int i=1;i<1000005;i++){
        arr[i]=1000001;
    }
    cout << oneone(X) <<'\n';
    return 0;
}

int oneone(int X){
    arr[1]=0;
    for(int i=1;i<(X/3)+1;i++){
        arr[i+1]=min(arr[i+1], arr[i]+1);
        arr[i*2]=min(arr[i*2], arr[i]+1);
        arr[i*3]=min(arr[i*3], arr[i]+1);
    }
    for(int j=(X/3)+1;j<(X/2)+1;j++){
        arr[j+1]=min(arr[j+1], arr[j]+1);
        arr[j*2]=min(arr[j*2], arr[j]+1);
    }
    for(int k=(X/2)+1;k<X;k++){
        arr[k+1]=min(arr[k+1], arr[k]+1);
    }
    return arr[X];
}