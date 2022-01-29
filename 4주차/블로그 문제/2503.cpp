// 숫자야구 https://www.acmicpc.net/problem/2503

#include <iostream>
#include <vector>
using namespace std;

int strike_cnt(int N, int n){
    int cnt=0;
    while(N>9){
        if(N%10==n%10) ++cnt;
        N = N/10;
        n = n/10;
    }
    if(N%10==n%10) ++cnt;
    return cnt;
}

int ball_cnt(int N, int n){
    int cnt=0;
    vector<int> v;

    while(N>9){
        v.push_back(N%10);
        N = N/10;
    }
    v.push_back(N%10);

    while(n>9){
        for(int i=0; i<3; i++){
            if(v[i]==n%10) ++cnt;
        }
        n = n/10;
    }
    for(int i=0; i<3; i++){
        if(v[i]==n%10) ++cnt;
    }

    return cnt;
}

bool checker(int N, int s, int b, int n){
    int S = strike_cnt(N, n);
    int B = ball_cnt(N, n) - S;
    return S==s && B==b;
}

bool checker_N(vector<int> v, int n){
    bool k = 1;
    for(int i=0; i<v.size()/3; i++){
        k = k && checker(v[3*i], v[3*i+1], v[3*i+2], n);
    }
    return k;
}

int main(){
    int N, n, cnt=0;
    cin>>N;
    vector<int> v;

    for(int i=0; i<3*N; i++){
        cin>>n;
        v.push_back(n);
    }

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            if(i!=j){
                for(int k=1; k<10; k++){
                    if(i!=k && j!=k){
                        if(checker_N(v, 100*i+10*j+k)) ++cnt;
                    }
                }
            }
        }
    }
    cout<<cnt;
}