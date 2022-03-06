#include <iostream>

const int MAX_SIZE = 8;
using namespace std;

int sorted[MAX_SIZE];

// i : 정렬된 왼쪽 리스트에 대한 인덱스   (list 1)
// j : 정렬된 오른쪽 리스트에 대한 인덱스 (list 2)
// k : 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left..mid] 와 list [mid+1 .. right] 의 합병 */
/* 숫자가 정렬되는 과정을 나타내는 함수*
    list[]는 call by reference로 배열 부르고, left, mid, right은 인덱스를 가리킴 */
void merge(int list[], int left, int mid, int right){

    int i, j , k;
    i = left;
    j = mid+1;
    k = left;

    /*분할 다하고, 정렬된 list의 합병*/
    // while문을 이용해서 i, j 인덱스와 비교함.
    while(i <= mid && j <= right){

        // 왜 k++ i ++ 인지 이해가 안갔는데, 이게 sorted[k] 자리에 list[i]를 넣고
        // i, k 둘다 1씩 증가하는 건가?

        /* 전치와 후치의 차이. */
        // 전치는 무조건 연산부터 진행한다. k값을 1 증가시키고 야튼 복사를 하여 출력하면 1 증가한 값이 나온다.
        // 후치는 변수 참조부터 하고, 메모리상에서 1 증가한다.
        // 이때, k++, j++는 해당 라인이 끝난 이후에 값이 1 증가하게 된다.
        // y= x++; 이면 현재 x값을 먼저 대입 시켜주고 그 뒤에 x를 증가시킨다. 
        // 즉, sorted[k++] = list[i++] 는 현재 k 인덱스에 l 인덱스를 대입 한후, k와 l 값을 1 증가시키는 후치 연산임.
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        }
        else{
           sorted[k++] = list[j++];
        } 
    } 
    // 남아 있는 값들을 일괄 복사함 (오른쪽 리스트 추가함)
    if(i>mid){
        for(int l = j; l <= right; l++){

            // 마찬가지로 l 인덱스 값을 k 인덱스에 넣어주고 그다음 k를 증가시킨다. (다음인덱스로 넘어가도록)
            // 이렇게 하면 장점이 k+=1 을 따로 쓰지 않고 인덱스 표현만으로 간단하게 표현 가능하다. 
            sorted[k++] = list[l];
        }

    }

    // 남아 있는 값들을 일괄 복사 ( 왼쪽 리스트 ) 
    else{
        for(int l = i; l <= mid; l++){
            sorted[k++] = list[l];
        }
    }

    // 배열의 sorted[] (임시배열) 의 리스트를 배열 list[]로 재복사
    for(int l = left; l <= right; l++){
        list[l] = sorted[l];
    }

}


// 합병 정렬
void merge_sort(int list[], int left, int right){
    int mid;
     
    // 내가 구현하기 힘들다고 생각했던 점이 
    // 어떻게 최소까지 분할할 것인가  인데,
    // 이 재귀 과정에서 어떻게 분할 + 정렬을 동시에 하는건지 이해가 안감.
    if(left < right){
        mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할
        merge_sort(list,left,mid); // 앞쪽 부분 리스트 정렬- 정복(conquer)
        merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 - 정복
        merge(list, left, mid, right); // 정렬된 2개의 부분배열을 합병하는 과정

    }

}

void main(){
    int i;
    int n = MAX_SIZE;
    // int list[n] 하면 변수여서 배열 선언이 안된다;

    int list[MAX_SIZE] = {21,10,12,20,25,13,15,22};

    // 합병 정렬 수행(left 배열의 시작 = 0, right 배열의 끝= 7)
    merge_sort(list, 0, n-1);

    // 정렬 결과 출력
    for(i = 0 ; i < n ; i++){
        printf("%d\n", list[i]);
    }
}