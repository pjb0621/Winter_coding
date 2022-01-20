// 손익분기점 https://www.acmicpc.net/problem/1712

#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    int income=0, cost=0, n=0;
    cin>>A>>B>>C;

    if(B>=C) cout<<-1;
    else cout<<A/(C-B)+1;
}