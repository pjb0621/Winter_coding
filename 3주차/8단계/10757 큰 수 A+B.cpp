/*
    큰 수 A+B
    https://www.acmicpc.net/problem/10757
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string A, B;
    int plus=0;
    cin >> A >> B;
    int i=A.length()-1;
    int j=B.length()-1;
    int max;
    if(i>j) max=i;
    else max=j;
    int x, y;
    char result[max];
    for(int k=max;k>=0;k--){
        if(i<0) x=0;
        else x=A[i]-'0';
        if(j<0) y=0;
        else y=B[j]-'0';
        if(x+y+plus>=10){
            result[k]=(x+y+plus)-10+'0';
            plus=1;
        }
        else{
            result[k]=x+y+plus+'0';
            plus=0;
        }
        i--;
        j--;
    }
    if(plus==1) result[0]='1';
    cout << result << "\n";
}