// 알파벳 찾기 https://www.acmicpc.net/problem/10809

#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    int n;
    cin>>S;
    for(char i='a'; i<='z'; i++){
        n = S.find_first_of(i);
        if(n==string::npos) cout<<-1<<" ";
        else cout<<n<<" ";
    }
}