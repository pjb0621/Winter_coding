// 별 찍기 - 10 https://www.acmicpc.net/problem/2447

// 시간초과된 버전인데 아까워서 놔둠

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> tri(vector<string> a, vector<string> b){
    vector<string> v(a.size());
    for(int i=0; i<a.size(); i++){
        v[i] = a[i]+b[i]+a[i];
    }
    return v;
}

vector<string> blank(int N){
    string b(N, ' ');
    vector<string> v(N, b);
    return v;
}

vector<string> f(int N){
    vector<string> v(N);
    vector<string> v1, v2, v3;
    vector<string> f0;

    if(N==1) v[0]="*";
    else{
        f0 = f(N/3);
        v1 = tri(f0, f0);
        v2 = tri(f0, blank(N/3));

        v=v1;
        v.insert(v.end(), v2.begin(), v2.end());
        v.insert(v.end(), v1.begin(), v1.end());
    }
    return v;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        cout<<f(N)[i]<<"\n";
    }
}