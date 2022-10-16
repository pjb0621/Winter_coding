/*
수 정렬하기
수의 개수가 최대 10,000,000 이므로
어떤 정렬을 할지 생각해보자.

정렬 반씩 쪼개서 보는것도 나쁘지 않을듯 하다
그냥 정렬은 n^2이라서 

버블정렬은 메모리 초과로 풀리지가 않는다.

이참에 딴건 몰라도 merge sort 하나만큼은 제대로 익혀보고 넘어가자.
손코딩 해야할듯..
*/

#include <iostream>
#include <vector>
using namespace std;


int main(){
    int arr[100000000];
    int n,tmp;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for(int i = n-1 ; i > 0 ;i--){
        for(int j = 0; j < i ; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

}