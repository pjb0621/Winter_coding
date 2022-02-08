/*
    배열 합치기
    https://www.acmicpc.net/problem/11728
*/

#include <iostream>

using namespace std;

long long arrA[1000000];
long long arrB[1000000];
long long newarr[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int NA, NB;
    cin >> NA >> NB;
    int N=NA+NB;
    for(int i=0;i<NA;i++){
        cin >> arrA[i];
    }
    for(int j=0;j<NB;j++){
        cin >> arrB[j];
    }
    int x=0, y=0;
    for(int k=0;k<N;k++){
        if(x>=NA){
            newarr[k]=arrB[y];
            y++;
        }
        else if(y>=NB){
            newarr[k]=arrA[x];
            x++;
        }
        else if(arrA[x]>arrB[y]){
            newarr[k]=arrB[y];
            y++;
        }
        else {
            newarr[k]=arrA[x];
            x++;
        }
    }
    for(int l=0;l<N;l++){
        cout << newarr[l] << ' ';
    }
    cout << '\n';
    return 0;
}