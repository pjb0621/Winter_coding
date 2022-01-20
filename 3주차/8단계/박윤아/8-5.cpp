// ACM 호텔 https://www.acmicpc.net/problem/10250

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int room_number(int H, int W, int N){
    int h, w;
    h = N%H;
    if(h==0) h=H;
    w = ceil((double)N/(double)H);
    return 100*h+w;
}

int main(){
    int T, H, W, N;
    cin>>T;
    vector<int> v(T);

    for(int i=0; i<T; i++){
        cin>>H>>W>>N;
        v[i]=room_number(H, W, N);
    }
    for(int i=0; i<T; i++){
        cout<<v[i]<<"\n";
    }
}