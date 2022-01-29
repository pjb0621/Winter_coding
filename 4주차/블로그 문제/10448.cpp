// 유레카 이론 https://www.acmicpc.net/problem/10448

#include <iostream>
#include <vector>
using namespace std;

bool f(int i, int n, int sum){
    while(i*(i+1)/2<=sum){
        if(n==1){
            if(i*(i+1)/2==sum) return 1;
        }
        else if(n>1){
            if(f(i, n-1, sum-i*(i+1)/2)) return 1;
        }
        i++;
    }
    return 0;
}

int main(){
    int N, n;
    cin>>N;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin>>n;
        v[i]=n;
    }

    for(int i=0; i<N; i++){
        cout<<f(1, 3, v[i])<<"\n";
    }
}
