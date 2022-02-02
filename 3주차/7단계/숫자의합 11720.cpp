/*
숫자의 합 11720번
https://www.acmicpc.net/problem/11720

*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    string s1 = "";
    // 공백문자를 신경안서도 되므로 cin 사용함
    cin >> n >> s1;
    int sum = 0;

    for (int i = 0; i < s1.length(); i++){
        // 문자열의 char 값을 -> 아스키코드로 변환
        int x = s1[i];
        // 아스키코드값에서 48을 빼서 실제 숫자로 바꿈.
        x = x - 48;
        sum += x;


    } 

    cout << sum << endl; 

    
}