// 덩치 https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
using namespace std;

class bulk{
    private:
        int h;
        int m;
    public:
        bulk(int _h, int _m): h(_h), m(_m){}
        int bigger(bulk b);
};

int bulk::bigger(bulk b){
    if(h<b.h && m<b.m){
        return 1;
    }
    else return 0;
}
    
int main(){
    int N, x, y;
    cin>>N;
    vector<bulk> v;
    vector<int> vcnt(N, 1);

    for(int i=0; i<N; i++){
        cin>>x>>y;
        v.push_back(bulk(x, y));
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j){
                vcnt[i] += v[i].bigger(v[j]);
            }
        }
    }

    for(int i=0; i<N; i++){
        cout<<vcnt[i]<<" ";
    }

}