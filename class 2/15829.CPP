/*
Hashing
26개의 알파벳 -> 각각의 정수로 치호나하기

순서가 달라졌을때 출력값도 달라지게 하려면?
수열의 각 항마다ㅏ 고유한 계수를 부여하자
대표적인건 항의 번호에 해당하는 만큼 특정한 숫자를 거듭제곱하여
곱해준 다음 더하는 것.

문제에서 주어진 해시함수는
위와 같고,
r의 값은 31
M은 1234567891 이다
항의번호란 인덱스를 의미한닷.

abcde가 주어지면

a -> 1
z -> 26 으로바꾸고

R의 거듭제곱을 인덱스 만큼 하면 된다.

*/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
    long long r = 31;
    long long m = 1234567891;
    int l;
    long long hash = 0;
    long long multiply = 1;
    string word;
    
    cin >> l >> word;

    for(int i = 0; i < l ; i++){
        long int alphabet = (word.at(i) - 96) % m;
        hash = (hash + (alphabet * multiply)) % m;
        multiply = (multiply * r) % m;
        
    }

    cout << hash << endl;
    

}
