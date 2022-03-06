/*
1929 소수구하기
https://www.acmicpc.net/problem/1929
*/



/*에라스토 테네스의 체 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){

    int M,N;
    cin >> M >> N;
    int sqn = sqrt(N);
    
    //int* arr = new int[N+1];
    int arr[1000001];
    arr[0] = 0;
    arr[1] = 0;
    // 1. 배열 초기화후, 0부터 N까지의 수를 저장
    // 이때 숫자와 인덱스를 일치시킴.
    for(int i = 2; i <= N; i++){
        arr[i] = i;
    }
    
    
    // 2. 2의 배수부터 sqrt(N) 까지 배수를 제거함.
    // 3. 소수인 경우에만 실행. 소수 아니면 0으로 초기화
    // 4. 소수인 경우 배수들을 전부 제거. 배수는 +i씩 증감
    for(int i = 2; i * i <= N; i++){
        if(arr[i] == 0) continue; 
            // i의 배수들을 하나씩 0으로 제거.
            for(int j = i * i; j <= N ; j += i){
                arr[j] = 0;
            }
        }
    

    // 5. 출력은 M부터 함
    // 원소가 0이면 소수 아니니까 컨티뉴
    for(int i = M; i<=N; i++)   {
        if(arr[i] != 0) cout << arr[i] << '\n'; 
    }

    // delete [] arr;

    return 0;
}