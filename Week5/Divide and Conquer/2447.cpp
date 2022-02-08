/*
    별 찍기
    https://www.acmicpc.net/problem/2447
*/

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int x=0, y=0;
    int NN=N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            x=i, y=j;
            NN=N;
            int flag=0;
            while(x>2 || y>2){
                if(x/(NN/3)==1 && y/(NN/3)==1){
                    cout << ' ';
                    flag=1;
                    break;
                }
                else{
                    x=x%(NN/3);
                    y=y%(NN/3);
                    NN=NN/3;
                }
            }
            if(x==1 && y==1) cout << ' ';
            else if(flag==0) cout << '*';
        }
        cout << '\n';
    }
    return 0;
}