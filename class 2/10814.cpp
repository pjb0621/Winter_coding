#include <iostream>
#include <utility>
#include <string>
using namespace std;

pair<int, string> sorted[100000];

int merge(pair<int, string> list[], int left, int mid, int right){
    int i, j, k;
    i = left; j = mid+1; k = left;
    pair <int, string> temp[100000]; // 결과를 담아둘 임시 배열

    // 분할된 임시 배열들을 합병
    while(i <= mid && j <= right){

        if(list[i].first < list[j].first){ // 왼쪽 배열의 원소를 집어 넣음
            temp[k++] = list[i++];
        }
        else if(list[i].first >= list[j].first){ // 오른쪽 배열의 원소를 집어 넣음
            temp[k++] = list[j++];
        }
    }

    // 배열에 남은값을 복사
    if(i > mid){ // 오른쪽 배열이 남음
        for(int l = j; l <= right; l++) temp[k++] = list[l];
    }
    else if(j > right){ // 왼쪽 배열이 남음
        for(int l = i; l <= mid; l++) temp[k++] = list[l];
    }

    // 배열 sorted[]로 temp[] 값을 재복사
    for(int l = left; l <= right; l++){
        sorted[l] = temp[l];
    }

}

void mergeSort(pair<int, string> list[], int left, int right){
    if(left != right){ // 배열의 크기가 1이 아니면 계속 분할함.
        int mid = (left + right)/2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}



int main(){
    int T;
    cin >> T;


}