// 단어의 개수 https://www.acmicpc.net/problem/1152

#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    int cnt=0, i=0;
    //공백을 포함한 문자열 S에 저장
    getline(cin, S);

    for(; i<S.size(); i++){

        if((char)S[i]!=' '){

            // 공백이 아닌 문자와 공백이 연달아 나오는 경우
            if((char)S[i+1]==' ') cnt++;
            
            // 공백이 아닌 문자와 널문자가 연달아 나오는 경우
            else if((char)S[i+1]=='\0') cnt++;
        }
    }
    cout<<cnt;
}