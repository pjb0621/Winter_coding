/*
11650과 거의 흡사하다
정렬 순서만 반대임

*/

#include <iostream>
#include <utility>
using namespace std;

pair<int,int> sorted[100000];
pair<int,int> temp[100000];


void merge(int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right){

        if(sorted[i].second < sorted[j].second){
            temp[k++] = sorted[i++];
        }
        else if(sorted[i].second > sorted[j].second){
            temp[k++] = sorted[j++];
        }
        else{ // x좌표가 같은 경우
            if(sorted[i].first <= sorted[j].first) temp[k++] = sorted[i++];
            else temp[k++] = sorted[j++];
        }
    }

    // 남은 배열 밀어넣기

    if(i > mid){
        while(j <= right) temp[k++] = sorted[j++];
    }
    else{
        while(i <= mid) temp[k++] = sorted[i++];
    }

    // 임시배열에서 실제 배열로 복사
    for(int l = left ; l <=right; l++) sorted[l] = temp[l];
}

void mergeSort(int left, int right){

    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }

}
int main(){
    int N;
    cin>> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        pair<int,int> temp (a,b);
        sorted[i] = temp;
    }

    mergeSort(0, N-1);

    for(int i = 0 ; i < N ; i++){
        cout << sorted[i].first << " " << sorted[i].second << '\n';
    }


}