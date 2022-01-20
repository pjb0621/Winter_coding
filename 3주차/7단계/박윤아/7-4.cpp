// 문자열 반복 https://www.acmicpc.net/problem/2675

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int T, R;
    string S, s;
    cin>>T;
    vector<string> v(T);

    //T회 반복 실행

    for(int i=0; i<T; i++){
        cin>>R;
        cin>>S;

        //s에 S의 각 문자마다 R회씩 반복하여 저장
        s="";
        for(int j=0; j<S.size(); j++){
            for(int k=0; k<R; k++){
                s += S[j];
            }
        }
        v[i]=s;
    }
    for(int i=0; i<T; i++){
        cout<<v[i]<<"\n";
    }
}