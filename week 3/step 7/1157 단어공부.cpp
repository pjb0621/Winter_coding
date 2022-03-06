#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    //1 문자열 입력 받고 소문자 처리 
    vector <int> vec_num(27);
    vec_num.assign(27,0);
    string str = "";
    cin >> str;
    transform(str.begin(),str.end(),str.begin(), ::tolower);
    

    // 3. 알파벳 나온 횟수만큼 알파벳 해당 인덱스 값 증가.
    for (int i = 0 ; str[i] !='\0'; i++){

        vec_num[str[i] - 'a']++;
    }

    // 4. 배열의 max 값 설정. 
    bool status = false;
    int max = 0;
    int max_index;
    for (int i = 0; i<vec_num.size(); i++){
        if(vec_num[i] > 0){
            if(vec_num[i] > max) {
                max_index = i;
                max = vec_num[i];
                status = false;
            }
            // max 값이 기존의 것과 같으면 status = true
            else if(vec_num[i] == max) status = true;

        }
    }

    // 5. max index에 해당하는 알파벳 출력.
    if(status) cout << '?' << endl;
    else{
        int x = max_index + 'A';
        char y = x;
        cout << y << endl;
        
    }
    





}
