// 회의실 배정 https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, s, e;
    int t=0, cnt=0;
    pair<int, int> p;
    vector<pair<int, int>> v;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>s>>e;
        p = {e, s};
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    for(int j=0; j<v.size(); j++){
        if(v[j].second>=t){
            t=v[j].first;
            cnt++;
        }
    }
     
    cout<<cnt;
}