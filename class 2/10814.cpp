#include <iostream>
#include <utility>
#include <string>
using namespace std;

pair<int, string> sorted[100000];
pair <int, string> temp[100000];
void merge(pair<int, string> list[], int left, int mid, int right){
    int i, j, k;
    i = left; j = mid+1; k = left;
     // 결과를 담아둘 임시 배열

    // 분할된 임시 배열들을 합병
    while(i <= mid && j <= right){

        if(list[i].first <= list[j].first){ // 왼쪽 배열의 원소를 집어 넣음
            temp[k++] = list[i++];
        }
        else if(list[i].first > list[j].first){ // 오른쪽 배열의 원소를 집어 넣음
            temp[k++] = list[j++];
        }
    }

    // 배열에 남은값을 복사
    if(i > mid){ // 오른쪽 배열이 남음
        while(j<=right){
            temp[k++] = list[j++];
        }
    }
    else { // 왼쪽 배열이 남음
        while(i <= mid){
            temp[k++] = list[i++];
        }
    }

    // 배열 sorted[]로 temp[] 값을 재복사
    for(int l = left; l <= right; l++){
        sorted[l] = temp[l];
    }

}

void mergeSort(pair<int, string> list[], int left, int right){
    if(left < right){ // 배열의 크기가 1이 아니면 계속 분할함.
        int mid = (left + right)/2;
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0 ; i < T; i++){
        int a;
        string b;
        cin >> a >> b;
        pair<int, string> temp (a,b);
        sorted[i] = temp;
    }
    
    mergeSort(sorted, 0, T-1);

    for(int i = 0; i < T; i++){
        cout << sorted[i].first << " " << sorted[i].second << '\n';
    }

    return 0;

}