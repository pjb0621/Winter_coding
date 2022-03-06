/*
분할정복으로 안풀고 다른 방식으로 해봄
*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> sorted;

void merge(vector<int> &list1, vector<int> &list2, int start, int end1, int end2){
   
    
    int i = start;  // list1 순회
    int j = start;  // list2 순회
    int k = start;  // sorted 순회

    while(i <= end1 && j <= end2){

        if(list1[i] <= list2[j]) sorted[k++] = list1[i++];
        else sorted[k++] = list2[j++];
    }

    if(i > end1){
        // 실수 포인트(end2는 마지막 인덱스임)
        for(int l = j; l <= end2; l++){
            sorted[k++] = list2[l];
        }

    }

    if(j > end2){
        // 실수 포인트(end1는 마지막 인덱스)
        for(int l = i; l <= end1; l++){
            sorted[k++] = list1[l];
        }

    }

    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector <int> arr1(N+1);
    vector <int> arr2(M+1);

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        arr1[i] = x;
    
    }

    for(int j = 0; j < M; j++){
        int y;
        cin >> y;
        arr2[j] = y;
    }
    
    sorted = vector <int> (N+M+1, 0);
    //실수 포인트3 : N, M으로 그냥 넣어버림. 
    merge(arr1, arr2, 0, N-1, M-1);

    for(int i = 0; i< N+M; i++){
        cout << sorted[i] << " ";
    }

    return 0;
    
}


// 자주하는 실수 vector <int> v(5,2)
// 2로 초기화된 5개의 원소를 가지는 vecotr v 생성.
