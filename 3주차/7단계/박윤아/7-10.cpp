// 그룹 단어 체커 https://www.acmicpc.net/problem/1316

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool group_checker(string S){
    vector<int> v(26);

    v[(int)S[0]-97] = 1;

    for(int i=1; i<S.size(); i++){

        //바로 앞 문자와 다른 문자가 나타나는 경우
        if(S[i]!=S[i-1]){
            
            //해당 문자가 나타난 횟수가 0인 경우 1로 저장
            if(v[(int)S[i]-97] == 0){
                v[(int)S[i]-97] = 1;
            }
            //해당 문자가 나타난 횟수가 0이 아닌 경우 그룹 단어 아님
            else{
                return 0;
            }
        }
    }
    return 1;

}

int main(){
    int N, cnt=0;
    string S;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>S;
        if(group_checker(S)){
            cnt++;
        }
    }
    cout<<cnt;
}