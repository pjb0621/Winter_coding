// 블랙잭 https://www.acmicpc.net/problem/2798

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M, n;
    int sum, min=0;
    cin>>N>>M;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }

    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){

                sum = v[i]+v[j]+v[k];
                if(sum<=M){
                    if(M-sum<M-min){
                        min = sum;
                    }
                }
                
            }
        }
    }
    cout<<min<<"\n";
}