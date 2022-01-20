// 다이얼 https://www.acmicpc.net/problem/5622

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, time=0;
    string S;
    cin>>S;

    for(int i=0; i<S.size(); i++){
        n = (int)S[i]-59;
        if(n<21) n/=3;
        else{
            if(n<25) n=7;
            else if(n<28) n=8;
            else if(n<32) n=9;
        }
        time += 1+n;
    }
    cout<<time;
}