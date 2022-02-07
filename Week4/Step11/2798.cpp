/*
    블랙잭
    https://www.acmicpc.net/problem/2798
*/

#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int cards[N];
    for(int i=0;i<N;i++){
        int card;
        cin >> card;
        cards[i]=card;
    }
    int max=-1;
    int sum=0;
    for(int a=0;a<N;a++){
        for(int b=a+1;b<N;b++){
            for(int c=b+1;c<N;c++){
                sum=cards[a]+cards[b]+cards[c];
                if(sum<=M && sum>max) max=sum;
            }
        }
    }
    cout << max;
    return 0;
}