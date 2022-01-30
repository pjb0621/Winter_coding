/*
    별 찍기 - 10
    https://www.acmicpc.net/problem/2447
*/

#include <iostream>
#include <cmath>

using namespace std;

int arr[6561][6561]={0,};

void star(int N, int a, int b){
    if(N==1) arr[a][b]=1;
    else {
        star(N/3, a, b);
        star(N/3, a+N/3, b);
        star(N/3, a+(N/3)*2, b);
        star(N/3, a, b+N/3);
        star(N/3, a, b+(N/3)*2);
        star(N/3, a+N/3, b+(N/3)*2);
        star(N/3, a+(N/3)*2, b+N/3);
        star(N/3, a+(N/3)*2, b+(N/3)*2);
    }
}

int main(){
    int N;
    cin >> N;
    star(N, 0, 0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==1) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}