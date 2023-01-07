#include <iostream>
#include <cmath>
using namespace std;
int arr[500000];
int temp[500000];
void merge(int arr[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<=mid && j <= right){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    if(i > mid){ // 왼쪽 배열이 남은 경우
        while( j<= right) temp[k++] = arr[j++];
    }
    else{
        while( i <= mid) temp[k++] = arr[i++];
    }

    for(int l = left; l <= right; l++) arr[l] = temp[l];
}


void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    
    int mode[8001] = {0,}; // 빈도수 계산하는 배열
    int n;
    cin >> n;

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr[i] = x;
        mode[x+4000] += 1;
    }
    /*
    for( int i = 0 ; i < n ; i++)cout << arr[i] << endl; 
    cout << "-----" << endl;
    */

    // 정렬
    mergeSort(arr, 0, n-1);


    int average, median, mod_num, range;
    // 산술평균
    int sum = 0;
    for(int i = 0; i< n; i++){
        sum += arr[i];
    }

    /*
    실수 타입 캐스팅이 중요한 문제,
    sum과 n이 모두 정수형이므로 5/3하면 소수점이 버려진다. 
    그래서 계산결과가 그냥 1.0000 으로 저장되므로
    sum, n중에 하나를 flaot으로 캐스팅하고 계산을 진행해야한다.

    자료형의 연산은 정말 정말 오차에 있어서 중요한 부분이므로 꼭! 숙지하자.
    */
    if(sum <= 0){
        float value = (float) sum/n;
        value -= 0.5;
        average = (int)value;
    }
    else{
        float value= (float)sum/n;
        value += 0.5;
        average = (int)value;

    }

    // 중앙값
    median = arr[n/2];

    // 최빈값
    int max, prev_max;
    bool flag = true; // 단 한번만 두번째로 작은 값 구하게 한다. 
    max = -1;
    for(int i = 0; i < 8001; i++){
        if(max < mode[i]){
            flag = true;
            max = mode[i];
            mod_num = i;
        }
        else if(max == mode[i]){ // 최빈값중 두번쨰로 작은 값 구하기.
            if(flag){
                max = mode[i];
                mod_num = i;
            }
            flag = false;
        }
    }


    mod_num -= 4000;

    range = arr[n-1] - arr[0];


    cout << average << endl;
    cout << median << endl;
    cout << mod_num << endl;
    cout << range << endl;

}