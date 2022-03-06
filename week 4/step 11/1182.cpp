/*
1182 부분 수열의 합
https://www.acmicpc.net/problem/1182

*/




#include <iostream>
using namespace std;

// tmp : 처음에 입력받은 arr[0], [1] ... [n-1] 자리
// index : 1부터 시작함.
// sum : 입력받은 합계
// size : 배열의 크기
// arr : 전체 배열

int arr[20];
int cnt = 0;
void hasSum(int tmp, int index, int sum, int size){

    
    // 기저 사례. 인덱스가 +1되서 size와 같아지면 종료
    if(index == size){
    
        return ;
    }


    // 다음 인덱스를 더했을때 sum과 같으면 cnt 증가
    // 그리고 tmp에 index추가하여 실행.
    if(tmp + arr[index] == sum){
        cnt += 1;
    }

        // 다음 arr을 더해도 sum이 안되는 경우라도
        // arr 더한 것과 안 더한 경우로 실행.
    hasSum(tmp, index+1, sum, size);
    hasSum(tmp+arr[index], index+1, sum, size);
    }
    
   


int main(){
    
    int n, s;
    cin >> n >> s;
    
   
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        arr[i] = x;

    }

    
    hasSum(0, 0, s, n);
    

    cout << cnt << endl;




    
}