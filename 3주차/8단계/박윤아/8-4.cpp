// 달팽이는 올라가고 싶다 https://www.acmicpc.net/problem/2869

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int A, B, V;
    cin>>A>>B>>V;
    cout.precision(10);
    cout<<ceil(((double)(V-A)/(double)(A-B)))+1;
}