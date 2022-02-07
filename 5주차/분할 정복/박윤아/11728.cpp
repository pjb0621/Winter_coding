// 배열 합치기 https://www.acmicpc.net/problem/11728

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A, res;

void merge(int a, int b){
    while(a<N && b<N+M){
        if(A[a]>A[b]){
            res.push_back(A[b]);
            b++;
        }
        else if(A[b]>A[a]){
            res.push_back(A[a]);
            a++;
        }
        else{
            res.push_back(A[a]);
            a++;
            res.push_back(A[b]);
            b++;
        }
    }

    while (a < N) res.push_back(A[a++]);
    while (b < N+M) res.push_back(A[b++]);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>N>>M;

    for(int i=0; i<N+M; i++){
        cin>>n;
        A.push_back(n);
    }

    merge(0, N);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}