/*
4344 평균은 넘겠지
https://www.acmicpc.net/problem/4344

입력은 테스트 케이스 c

둘째 줄부터 학생의 수 N과 N명의 점수가 주어진다. 

출력은 한줄 씩 평균을 넘는 학생들의 비율을 반올림 하여 소수점 셋째자리까지 출력.

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    cin.tie(NULL);
    

    int c, sum=0, avg, cnt = 0;
    cin >> c;
    int arr[1000];
    for(int i = 0; i < c; i++){
        arr[1000] = {0,};
        int n = getchar();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            arr[i] = x;
            sum += arr[i];
        
        }
    

        avg = sum / n;
     

        for(int i = 0; i < n ; i++){
            if(arr[i] > avg) cnt ++;
        }
        double percent = cnt/n*100;
        cout << fixed;
        cout.precision(3);
        cout << percent << '%' << '\n';
        sum = 0, cnt = 0;
        
    }

    return 0;
}



