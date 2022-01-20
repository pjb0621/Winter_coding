// 숫자의 합 https://www.acmicpc.net/problem/11720

#include <iostream>
using namespace std;

int main(){
    int N, sum=0;
    string s;
    cin>>N;
    cin>>s;
    for(int i=0; i<N; i++){
        sum += (int)s[i]-48;
    }
    cout<<sum;
}