/*
첫째줄에 8개의 숫자가 주어진다.
숫자가 계속해서 증가하면 ascending
숫자가 계속해서 감소하면 descending
둘다 아니면 mixed

state를 2개 만들어서,
계속해서 previous state와 current state가 다르면 mixed
마지막까지 같다면, state가 ascending인지 descending인지 체크해서 확인해보자.

1. 1,2번째 원소를 비교해서 초기 세팅을 해둔다.
2. i, i+1번째 원소를 비교하여 increasing이면 is_ascedning = true하고, is_descending과 비교하여
둘이 같으면 바로 break후 mixed 출력
descending도 마찬가지.

3. 마지막까지 loop 후, is_ascending, is_descending 비교하여 출력.


*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[8];
    bool is_ascending = false;
    bool is_descending = false;

    for (int i = 0 ; i < 8 ; i++){
        cin >> arr[i];
    }

    // 첫,둘 원소 비교
    if(arr[0] > arr[1]){
        is_ascending = false;
        is_descending = true;
    }else{
        is_ascending = true;
        is_descending = false;
    }

    for(int i = 1; i < 7; i++){
        if(arr[i] < arr[i+1]){
            is_ascending = true;
            if(is_ascending == is_descending){
                cout << "mixed"<< endl;
                return 0;
            }
        }else{
            is_descending = true;
            if(is_ascending == is_descending){
                cout << "mixed"<< endl;
                return 0;
            } 
        }
    }

    // last check
    string result = (is_ascending) ? "ascending" : "descending";

    cout << result << endl;


}