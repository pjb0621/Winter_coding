// 네 번째 점 https://www.acmicpc.net/problem/3009

#include <iostream>
using namespace std;

void find_missing(int x1, int x2, int x3){
    if(x1==x2) cout<<x3;
    else if(x1==x3) cout<<x2;
    else cout<<x1;
}

int main(){
    int x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    find_missing(x1, x2, x3);
    cout<<" ";
    find_missing(y1, y2, y3);
}