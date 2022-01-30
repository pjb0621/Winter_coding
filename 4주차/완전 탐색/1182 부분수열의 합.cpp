/*
    부분수열의 합
    https://www.acmicpc.net/problem/1182
*/

#include <iostream>

using namespace std;

int count=0;

void sums(int set[], int S, int N){
    if(N==1){
        if(set[0]==S) count++;
        if(S==0) count++;
    }
    else{
        int nset[N-1];
        for(int a=0;a<N-1;a++){
            nset[a]=set[a];
        }
        sums(nset, S-set[N-1], N-1);
        sums(nset, S, N-1);
    }
}

int main() {
    int N, S;
    cin >> N >> S;
    int set[N];
    for(int i=0;i<N;i++){
        cin >> set[i];
    }
    sums(set, S, N);
    if(S==0) count--;
    cout << count << '\n';

    return 0;
}