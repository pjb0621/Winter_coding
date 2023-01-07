/*
스택을 이용해서 푸는 문제,
0이 들어올때마다 pop을 실행하면 된다.
stl이용해서 풀어보자
*/
#include <iostream>
#include <stack>
using namespace std;

int main(){

    int k, num;
    cin >> k;

    stack<int> s;
    while(k--){
        cin >> num;
        if(num == 0 && !s.empty()) s.pop();
        else s.push(num);
    }

    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;

}