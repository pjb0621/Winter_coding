// 단어 공부 https://www.acmicpc.net/problem/1157

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string S;
    vector<int> v(26);
    int max,  first_max, last_max;
    cin>>S;

    // 대문자로 변경
    for(int i=0; i<S.size(); i++){
        S[i] = toupper(S[i]);
    }
    // 알파벳 별로 나온 횟수 카운트
    for(int i=0; i<S.size(); i++){
        v[(int)S[i]-65] += 1;
    }

    // 나온 횟수의 최댓값 구한 후 최댓값이 나오는 첫 번째 인덱스 및 마지막 인덱스 구하기

    max = *max_element(v.begin(), v.end());
    first_max = (int)(find(v.begin(), v.end(), max)-v.begin());
    last_max = 25-(int)(find(v.rbegin(), v.rend(), max)-v.rbegin());

    //첫 번째 인덱스와 마지막 인덱스 비교
     
    //같으면 최댓값이 하나이므로 해당 알파벳 출력
    if(first_max==last_max){
        cout<<(char)(first_max+65);
    }
    //다르면 최댓값이 여럿이므로 ? 출력
    else{
        cout<<"?";
    }
}

/*
int main(){
    string S;
    vector<int> v(26);
    int max,  first_max, last_max;
    cin>>S;

    for(int i=0; i<S.size(); i++){
        S[i] = toupper(S[i]);
    }
    for(int i=0; i<S.size(); i++){
        v[(int)S[i]-65] += 1;
    }

    max = *max_element(v.begin(), v.end());
    for(int j=0; j<26; j++){
        if(max==v[j]){
            first_max=j;
            break;
        }
    }
    for(int j=0; j<26; j++){
        if(max==v[j]){
            last_max=j;
        }
    }
    if(first_max==last_max){
        cout<<(char)(first_max+65);
    }
    else{
        cout<<"?";
    }
}
*/