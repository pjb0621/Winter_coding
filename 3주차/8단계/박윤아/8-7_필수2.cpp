// 설탕 배달 https://www.acmicpc.net/problem/2839

#include <iostream>
using namespace std;


int main(){
    int N, min, cnt;
    cin>>N;
    min = 5000;

    for(int i=0; i<=N/5; i++){
        if((N-5*i)%3==0){
            cnt = i+(N-5*i)/3;
            if(min>cnt) min=cnt;
        }
    }
    if(min==5000) cout<<-1;
    else cout<<min;
}