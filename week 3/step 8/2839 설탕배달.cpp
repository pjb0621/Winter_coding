/*
2839 설탕배달
https://www.acmicpc.net/problem/2839
*/

#include <iostream>
using namespace std;

int main(){
    // 부정방정식 이용
    // x는 3kg 양동이, y는 5kg 양동이

    int N;
    cin >> N;

    // 1. 정수 X의 최대 range를 구한다.
    int x_range = 0, y_range = 0;
    while(3 * x_range < N){
        x_range ++;
    }
    while(5 * y_range < N){
        y_range ++;
    }


    // 2. for문으로 x range 만큼 순회
    // y가 정수인 경우, x+y = m을 계산하고
    // 최소 횟수를 갱신 시킴.
    int x,y, m;
    int min = -1;
    for(x=0; x<= x_range ; x++){
    
    for(y=0; y <= y_range; y++){

        if((3*x+5*y) == N){
            m = x+y;

            if(min == -1) min = m;
            else if(m < min) min = m;
        }
    }
    }

    // 3. 출력
    cout << min << endl;
    return 0;
}