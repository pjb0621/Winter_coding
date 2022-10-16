/*
ACM 호텔

n번째 손님이 머무를 방번호는
N을 h로 나눈 나머지 + (몫+1) 나타낸 방번호이다.

*/

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int h,w,n, room_num;
        cin >> h >> w>> n;
        if(n%h == 0){
            room_num = h*100 + n/h;
        }
        else{
            room_num = (n%h)*100+ (n/h +1);
        }
        cout << room_num << endl;
    }
}