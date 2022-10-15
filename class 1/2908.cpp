/*
상수는 모든 숫자를 거꾸로 읽는다.
서로 다른 세자리 숫자가 주어질때,
상수의 기준에서 대수비교를 해보자.

*/

#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a>> b;

    int new_a, new_b;
    new_a = (a % 10) * 100 + (( a/10 )% 10) * 10 + (a/100);
    new_b = (b % 10) * 100 + (( b/10 )% 10) * 10 + (b/100);

    if(new_a > new_b){
        cout << new_a<<endl;
    }
    else{
        cout << new_b << endl;
    }
}