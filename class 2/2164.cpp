/*
구현으로 C++ STL <queue> 이용
사용 메소드는 front(), back(), pop()
size() : 큐의 현재 사이즈 반환

*/



#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    int N;
    cin >> N;
    for(int i = 1 ; i <= N ; i++) q.push(i);

    while(q.size() != 1){
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << endl;
    
}