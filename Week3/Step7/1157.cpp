/*
    단어 공부
    https://www.acmicpc.net/problem/1157
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string words;
    int count[27]={0, };
    cin >> words;
    for(int i=0;i<words.length();i++){
        int x=words[i]-'A';
        if(x<26){
            count[x+1]++;
        }
        else{
            count[x-31]++;
        }
    }
    int max=0, lot=0;
    for(int j=1;j<27;j++){
        if(count[j]>count[max]){
            max=j;
            lot=0;
        }
        else if(count[j]==count[max]){
            lot=1;
        }
    }
    if(lot!=1 && max!=0){
        char result=max+64;
        cout << result << endl;
    }
    else{
        cout << "?" << endl;
    }
    return 0;
}