#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector <string> str;
    int cnt, T;
    string tmp;
    cnt = 0;
    cin >> T;

    getchar(); // 숫자 이후 공백 제거 
    for(int i = 0 ; i < T; i++){
        getline(cin, tmp);
        str.push_back(tmp);
    }

    // for(int i = 0 ; i < T; i++) cout << str[i] << endl;

    

    for(int i = 0; i < T; i++){

        //cout << "START" << endl;
        //cout << str[i] << endl;
        
        // cout << str[i].size() << endl;

        if(str[i].size() % 2 == 1){
            cout << "NO" << endl;
            continue;
        }

        
        for(int j = 0; j < str[i].size(); j++){
           // cout << str[i].at(j) << "";
            if(str[i].at(j) == ')') cnt--;
            else cnt++;

            if(cnt < 0){
                break;
            }
        }
         
       
        
        if(cnt == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        cnt = 0; // 사이클마다 초기화

        //cout << " ----------- " << endl;
    }

}