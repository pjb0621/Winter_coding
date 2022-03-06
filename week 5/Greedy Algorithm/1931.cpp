/*
1931 회의실 배정
https://www.acmicpc.net/problem/1931

2차원 벡터의 안쪽 원소를 기준으로 정렬을 해야하는데\

이에 대한 stl 문법의 이해가 필요해보인다.
https://leeeegun.tistory.com/5
https://learncom1234.tistory.com/6
참고자료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare1(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

bool compare2(vector<int> a, vector<int> b){
    return a[0] < b[0];
}


int main(){

    int n;
    cin >> n;
    // 1. n 입력 받고 2차원 벡터 선언
    // n행 2열의 벡터
    vector <vector <int>> schedule(n,vector<int>(2,0));

    // 2. 벡터 정렬
    int x,y;
    for(int i = 0; i < n ; i++){
      

        cin >> x >> y;
        schedule[i][0] = x;
        schedule[i][1] = y;
 
    }

    sort(schedule.begin(), schedule.end(), compare2);
    sort(schedule.begin(), schedule.end(), compare1);
  

   
    // 3. 끝나는 시간이 가장 빠른걸 먼저 찾는다. 
    // 끝나는 시간 < = 시작 시간인 첫번째 인덱스를 찾는다 (정렬 되어 있음)
    // cnt ++ 증가하고 다시 반복한다. 
    // 코너 케이스로 회의가 겹치는 경우를 제외해야한다.
    // ex  1 1  1 1  1 1 은 모두 같다. 
    // 즉, [tmp][1]와 schdule[i][0] 같을떄 비교를 한번 한다.

    // +) 끝나는 시간이 같으면 시작 시간 순으로 정렬을 한번더 해야한다. 
    // 정렬 하고 나니까 회의가 겹치는 경우를 if문으로 고려한걸 빼도 되네.. 이유는 모르겠다
    int tmp = 0, cnt = 1;

    
    for(int i = 1; i < n; i++){
      
        // [tmp][1] 은 끝나는 시간, [i][0] 은 시작 시간.
        if(schedule[tmp][1] <= schedule[i][0]){
            tmp = i;
            cnt ++;
        } 
    }

    cout << cnt << endl;

}

