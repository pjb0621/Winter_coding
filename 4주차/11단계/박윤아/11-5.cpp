// 영화감독 숌 https://www.acmicpc.net/problem/1436

#include <iostream>
#include <vector>
using namespace std;

bool find_666(int N){
    vector<int> v;
    while(N>=10){
        v.push_back(N%10);
        N = N/10;
    }
    v.push_back(N);

    for(int i=0; i<v.size()-2; ++i){
        if(v[i]==6 && v[i+1]==6 && v[i+2]==6){
            return 1;
        }
    }
    return 0;
}
    
int main(){
    int N, cnt=0, n=666;
    cin>>N;
    
    while(cnt<N){
        if(find_666(n)) ++cnt;
        n++;
    }
    cout<<n-1;
}

