/*
덩치 등수 = N명의 집단에서 자신보다 더 "큰 덩치" 의 사람 의수
브루트포스로 2중 for문으로 순회하며
자신을 제외한 나머지 인덱스와 비교하여 덩치 비교 후 출력바로하기
*/

#include <iostream>
#include <utility>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int,int> kg_cm[50];

    for(int i = 0; i < n ; i++){
        int a,b;
        cin >> a >> b;
        pair <int, int> temp(a,b);
        kg_cm[i] = temp;
    }

    for(int i = 0 ; i < n ; i++){

        int kg = kg_cm[i].first;
        int cm = kg_cm[i].second;
        int rank = 1;
        for(int j = 0; j < n ; j++){
            if(j == i) continue; // 동일 인덱스 생략
            
            if(kg < kg_cm[j].first && cm < kg_cm[j].second) rank++;

        }

        cout << rank << " " ;
    }
}