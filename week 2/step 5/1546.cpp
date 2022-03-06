/*
평균 1546
https://www.acmicpc.net/problem/1546

점수를 조작하고자 하는데

최대값이 M이면, 
모든 점수를 score/M*100으로 고친다.

이때의 새로운 평균을 구하라.

시험본 과목의 최댓값은 1000이다. 

*/

#include <iostream>
using namespace std;

int main(){
    int n;
    long double arr[1001];
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        long double x;
        cin >> x;
        arr[i] = x;
    }

    // 점수 조작을 위해 최대값을 찾는다.
    long double max = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > max) max = arr[i];
    }
    // 배열에 저장된 각점수를 조작하고 average 계산
    long double sum = 0, tmp = 0;
    for(int i =0; i < n ; i++){
        tmp = (arr[i]/max)*100;
        sum += tmp;
    }

    long double average = sum/n;
    cout << average << '\n';

    return 0;
}