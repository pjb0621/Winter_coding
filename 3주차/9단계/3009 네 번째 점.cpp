/*
    네 번째 점
    https://www.acmicpc.net/problem/3009
*/

#include <iostream>

using namespace std;

int main() {
    int x[4]={0,};
    int y[4]={0,};

    //(x,y) 3개 입력받기
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];

    //네 번째 점의 x좌표 구하기
    if(x[0]==x[1]) x[3]=x[2];
    else x[3]=x[0]+x[1]-x[2];

    //네 번째 점의 y좌표 구하기
    if(y[0]==y[1]) y[3]=y[2];
    else y[3]=y[0]+y[1]-y[2];
    
    //출력
    cout << x[3] << " " << y[3] << "\n";
    return 0;
}