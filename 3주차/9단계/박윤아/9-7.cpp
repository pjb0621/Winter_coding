// 직사각형에서 탈출 https://www.acmicpc.net/problem/1085

#include <iostream>
using namespace std;

int main(){
    int x, y, w, h;
    int x_w, y_h;

    cin>>x>>y>>w>>h;

    x_w = min(x, abs(x-w));
    y_h = min(y, abs(y-h));
    cout<<min(x_w, y_h);
}