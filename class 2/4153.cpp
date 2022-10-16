/*
직각삼각형인지 구분하는 함수를 짜보자.
입력은 여러개의 테스트 케이스로 이루어지며,
마지막 줄에는 0 0 0 으로 입력된다.
-> while 문 이용

벡터를 이용해서
정렬을 해서 가장 긴쪽을 마지막 인덱스로 두게 하자.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    vector <int> triangle;
    triangle.resize(3);

    while(1){
    
        cin >> triangle[0] >> triangle[1] >> triangle[2];
        if(triangle[0] == 0 && triangle[1] == 0 && triangle[2] == 0) break;
        std::sort(triangle.begin(), triangle.end());
        bool state = pow(triangle[2],2) == pow(triangle[1],2) + pow(triangle[0],2);
        if(state) cout << "right" << endl;
        else cout <<"wrong" << endl;
    }
    
    return 0;
}