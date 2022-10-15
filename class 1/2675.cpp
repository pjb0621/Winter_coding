/*
첫재 줄에 테스트케이스의 개수 T(1~1000)가 주어진다.
각 테스트 케이스는 반복횟수 R, 문자열 S가 공백으로 구분되어 주어진다.
문자열 S의 길이는 적어도 1이며, 20글자를 넘지 않는다.

문자열의 각 문자를 반복횟수만큼 늘려서 새로운 문자열 P를 출력한다.
C++ 의 String을 이용해서 할 계획이다.
테스트케이스가 여러개이므로 vector를 이용하여 string 여러개를 담아둘 것이다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;

    std::vector <int> R_vec;
    std::vector <string> str_vec;
    std::vector <string> result_vec;
    R_vec.resize(T);
    str_vec.resize(T);
    result_vec.resize(T);
    // 테스트케이스 입력부
    for(int i = 0 ; i < T; i++){
        cin >> R_vec[i] >> str_vec[i];
    }

    for(int i = 0 ; i< T; i++){
        for(int j = 0; j < str_vec[i].size(); j++){
            result_vec[i].append(R_vec[i],str_vec[i][j]);
        }
    }

    for(int i = 0; i < T; i++){
        cout << result_vec[i] << endl;
    }


    
}