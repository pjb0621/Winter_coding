/*
배열로도 못풀겠다
 STL 쓰자..
 
*/

#include <iostream>
using namespace std;


int main(){

    int N, M, sum, head, tail, index, min,size; 
    cin >> N >> M;
    head = 0;
    tail = N-1;
    size = N;

    int* arr = (int*)malloc(sizeof(int) * N);
    int* find_num = (int*)malloc(sizeof(int) * M);
    for(int i = 1; i <= N; i++) arr[i] = i;

    for(int i = 0 ; i < M; i++){
        cin >> find_num[i];
    }

    // 배열로 풀 경우, head로 맨앞의 인덱스를 가리키게 한다.
    // 2번 연산, 3번 연산에 따라서 head 값을 바꿔 인덱스 조정
    
    // 매 루프마다 해당 원소의 인덱스를 찾는다
    for(int i = 0; i < M ; i++){

        for(int j = 0; j < size; j++){
            if(find_num[i] == arr[j]) index = j;
        }

        //head, tail과의 거리중 짧은 쪽을 택함
        if(index - head <= tail - index){ // move_left
            min = index - head;
            head += min;
            tail = (tail + min) % N;
            
            // pop
            head += 1;
            N -= 1;
        }
        
        else{ // move_right
            min = tail - index;
            tail -= min;
            head = head - min + N;

            // pop
            head += 1;
            N -= 1;
        }

        sum += min;
    }

    cout << sum << endl;








    
}