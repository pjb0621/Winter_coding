// 크로아티아 알파벳 https://www.acmicpc.net/problem/2941

#include <iostream>
#include <string>
using namespace std;

int main(){
    int i=0, cnt=0;
    string S;
    cin>>S;

    while(i<S.size()){
        if(i+1<S.size()){
            if(S[i]=='c' && S[i+1]=='='){
                cnt++;
                i += 2;
            }
            else if(S[i]=='s' && S[i+1]=='='){
                cnt++;
                i += 2;
            }
            else if(S[i]=='z' && S[i+1]=='='){
                cnt++;
                i += 2;
            }
            else if(S[i]=='c' && S[i+1]=='-'){
                cnt++;
                i += 2;
            }
            else if(S[i]=='d' && S[i+1]=='-'){
                cnt++;
                i += 2;
            }
            else if(S[i]=='l' && S[i+1]=='j'){
                cnt++;
                i += 2;
            }
            else if(S[i]=='n' && S[i+1]=='j'){
                cnt++;
                i += 2;
            }
            else if(i+2<S.size()){
                if(S[i]=='d' && S[i+1]=='z' && S[i+2]=='='){
                    cnt++;
                    i += 3;
                }
                else{
                    i++;
                    cnt++;
                }
            }
            else{
                i++;
                cnt++;
            }
        }
        else{
            i++;
            cnt++;
        }
    }
    cout<<cnt;
}