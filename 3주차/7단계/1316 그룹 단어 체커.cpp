/*
    그룹 단어 체커
    https://www.acmicpc.net/problem/1316
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, count=0, group=1;
    string word;
    int alphabet[26]={0, };
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> word;
        group=1;
        for(int j=0;j<word.length();j++){
            int x=word[j]-'A';
            if(word[j-1]!=word[j]){
                alphabet[x]++;
                if(alphabet[x]>1) group=0;
            }
        }
        if(group==1){
            cout << word << endl;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}