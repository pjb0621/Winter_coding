/*
1152번 단어의 개수
https://www.acmicpc.net/problem/1152
*/

// 문자열이 주어지면, 몇개의 단어가 있는지 구하라
// 한단어가 여러번 등장하면 등장한 횟수만큼 센다.

// 단어는 공백 한개로 구분된다. 

// 이번문제는 문자열 배열로 풀이함

#include <iostream>
#include <string>

using namespace std;

int main(){

    // 1. 문자열을 입력 받음(공백 포함)
    char str[1000001];
    cin.getline(str, 1000001);
    
    bool front;
    bool back; 

       
    // 2. 문자열의 맨 앞과 뒤 공백 상황에 따라서 상태 변수를 설정한다.

    if (str[0] == 32) front = true;
    else front = false;

    int length = 0;
    while(str[length]) length++;

    if (str[length - 1] == 32) back = true;
    else back = false;
    
    // 3. 공백을 만날때마다 카운트를 늘린다.
    // 문자열 공백 포함 길이도 계산한다.

    
    int cnt = 0;
    int i = 0;
    while(i < length){

        if(str[i] == 32){
            cnt ++;     
        }
        i++;     
    }

    // 4. front , back 변수 값에 따라 다른 값을 출력한다.

    if (front == true && back == false){
        cout << cnt << endl;
    }
    if (front == false && back == true){
        cout << cnt << endl;
    }

    if(front == false && back == false){
        cnt ++;
        cout << cnt << endl;
    }
    if(front == true && back == true){
        cnt --;
        cout << cnt << endl;
    }
    return 0;
}