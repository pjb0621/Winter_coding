/*
수정렬하기 2
Merge sort 이용함.

이것도 수가 중복되지 않는다는점을 이용해서
해당하는 수가 입력되면 인덱스가 True로 바꾼다음에 
true인것만 순서대로 출력하면 됨.

*/

#include <iostream>
using namespace std;
int sorted[1000000];


void merge(int list[], int left, int mid, int right){

    int i, j, k;
    i = left;
    j = mid+1;
    k = left;

    while(i <= mid && j <= right){

        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }

    if(i <= mid){
        for(int x = i; x <= mid; x++){
            sorted[k++] = list[x];
        }
    }
    else{
        for(int x = j; x <= right; x++){
            sorted[k++] = list[x];
        }
    }

    for(int x = left; x<=right; x++){
        list[x] = sorted[x];
    }
}

void merge_sort(int list[], int left, int right){

    if(left < right){
        int mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left,mid,right); // 가장 작은 리스트부터 merge 콜이 들어간다.
    }

}


int main(){
    int N;
    cin >> N;
    int list[N];
    for(int i = 0; i < N; i++){
        cin >> list[i];
    }

    merge_sort(list, 0, N-1);

    for(int i = 0; i < N; i++){
        cout << list[i] << '\n';

    }



    return 0;
}