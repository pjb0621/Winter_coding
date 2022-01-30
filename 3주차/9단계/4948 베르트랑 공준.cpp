/*
    베르트랑 공준
    https://www.acmicpc.net/problem/4948
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n=0, count=0;
    cin >> n;
    while(n!=0){
        int lst[2*n]={0,};
        lst[0]=1;
        count=0;
        for(int i=2;i<=sqrt(2*n);i++){
            if(lst[i-1]==0){
                for(int x=i*i;x<=2*n;x+=i){
                    lst[x-1]=1;
                }
            }
        }
        for(int j=n+1;j<=2*n;j++){
            if(lst[j-1]==0) count++;
        }
        cout << count << "\n";
        cin >> n;
    }
    return 0;
}