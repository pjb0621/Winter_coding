// 직각삼각형 https://www.acmicpc.net/problem/4153

#include <iostream>
#include <vector>
using namespace std;

bool check_right_triangle(int a, int b, int c){
    int A, B, C;
    A = min(a, b);
    B = min(max(a, b), c);
    C = max(max(a, b), c);
    if(A+B<=C) return 0;
    if(A*A+B*B!=C*C) return 0;
    return 1;
}

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    vector<bool> v;

    while(a!=0){
        v.push_back(check_right_triangle(a, b, c));
        cin>>a>>b>>c;
    }
    for(int i=0; i<v.size(); i++){
        if(v[i]) cout<<"right"<<"\n";
        else cout<<"wrong"<<"\n";
    }
}