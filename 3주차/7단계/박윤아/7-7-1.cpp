// 상수 https://www.acmicpc.net/problem/2908

// integer 연산 이용한 풀이

#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin>>A>>B;

    A += 99*(A%10)-99*(A/100);
    B += 99*(B%10)-99*(B/100);

    if(A>B) cout<<A;
    else cout<<B;
}
