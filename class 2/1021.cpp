/*
N개의 원소를 포함한 양방향 순환 큐
큐에서 진행가능한 연산은 3가지로,
1. 첫번째 원소를 뽑아낸다
2. 왼쪽으로 한칸 이동시킨다
(1,2,3,4,... k) -> (2,3,4, ... , k , 1)
3. 오른족으로 한칸 이동시킨다
(1,2,3,4,..., k) -> (k, 1, 2, ... k-1)
큐에 처음에 포함되어있던수 N이 주어지고,
뽑아내려하는 원소의 위치가주어짐

이때, 그 원소를 주어진 순서대로 뽑아내는데 드는
2번
3번연산의 최솟값을 출력.

첫째줄에 큐의 크기 N과 수의 개수 m이 주어진다.
둘쨰줄에는 지민이가 뽑아내려고하는 수의 위치가 순서대로 주어진다.


*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class UnderflowException{};
template<typename T>
class ListNode{
public:
    T value;
    ListNode<T> *next;

    ListNode<T>(): next(nullptr){}
    ListNode<T>(T value1, ListNode<T> *next1): value(value1), next(next1){};
};

template<typename T>
class Queue{
public:
    int size;
    ListNode<T> *head, *tail;

    // 생성자
    Queue<T>() : size(0), head(nullptr), tail(nullptr){}

    // 소멸자
    ~Queue<T>(){
        ListNode<T> *t1 = head, *t2;
        while(t1 != nullptr){
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }

    // 멤버 함수
    // push, front, pop은 기존에 있는 코드이용
    // search, move_left, move_right은 스스로 만들기.
    
    void push(T value){
        // 큐가 비어있을 경우
        if(size == 0 ) head = tail = new ListNode<T>(value, nullptr);
        else{
            tail -> next = new ListNode<T>(value, nullptr);
            tail = tail->next;
        }
        size++;
    }

    T front(){ // 맨 앞의 원소 반환
        try{
            if(size == 0) throw UnderflowException();

            return head->value;

        }
        catch(UnderflowException e){
            cerr << "큐가 비어있는데 front 연산을 시도했습니다." << endl;
            exit(1);
        }
    }

    void pop(){
        try{
            //예외처리 : 큐가 비어있음
            if(size == 0 ) throw UnderflowException();
            ListNode<T> *temp = head->next;
            delete head;
            head = temp;
            if(head == nullptr) tail = nullptr; // 크기가 0이 됨
            size--;
        }
        catch(UnderflowException e){
            cerr << "큐가 비어있는데 pop 연산을 시도했습니다." << endl;
            exit(2);
        }
    }

    int search(T value){ // 값을 찾아 첫번째 인덱스 리턴, 없으면 -1 리턴
        ListNode<T> *temp = head;
        for(int i = 0; i < size; i++){
            if(temp->value == value) return i;
            temp = temp->next;
        }
        return -1; // 못 찾음
    }

    void move_left(){
        // front에 있는걸 tail로
        // front->next가 head로 간다.
        ListNode<T> *temp = head;
        tail -> next = head;
        head = head->next;
    }

    void move_right(){
        
        ListNode<T> *dest;
        for(int i = 0; i < size-1; i++) dest = dest->next;
        head = tail;
        tail = dest;
    }

    void print(){

        ListNode<T> *temp = head;
        for(int i = 0; i<size; i++){
            cout << temp->value;
            temp = temp->next;
            if( i < size-1) cout << ", ";
        }
        cout <<'\n';
    }
};

int main(){

    Queue<int> Q;
    int N, M, sum = 0;
    cin >> N  >> M;
    for(int i = 1; i <= N; i++){
        Q.push(i);
    }

    int num[M];
    for(int i = 0 ; i < M ; i++){
        cin >> num[i];
    }

    for(int j = 0 ; j < M; j++){
        int index = Q.search(num[j]);
        int min_num = min(index, (Q.size - index + 1));
        sum += min_num;
        if(min_num == 0){
            Q.pop();
        }
        else if(index <= Q.size - index + 1){ // move_left 하는 경우
            for(int i= 0; i < min_num; i++) Q.move_left();
            Q.pop();
        }
        else{ // move_right하는 경우
            for(int i = 0 ; i < min_num; i++) Q.move_right();
            Q.pop();
        }

        cout << " ----- " << endl;
        cout << "index : " << index << endl;
        cout << "min_num : " << min_num << endl;
        Q.print();
        cout << " ----- " << endl;
        cout << j << endl;

    }

    /*
        int index = Q.search(num.front());
        int min_num = min(index, (Q.size - index + 1));
        sum += min_num;
        if(min_num == 0){
            Q.pop();
        }
        else if(index <= Q.size - index + 1){ // move_left 하는 경우
            for(int i= 0; i < min_num; i++) Q.move_left();
            Q.pop();
        }
        else{ // move_right하는 경우
            for(int i = 0 ; i < min_num; i++) Q.move_right();
            Q.pop();
        }

        cout << " ----- " << endl;
        cout << "index : " << index << endl;
        cout << "min_num : " << min_num << endl;
        Q.print();
        cout << " ----- " << endl;

        num.erase(remove(num.begin(), num.end(), num.front()), num.end());
         for(int i = 0 ; i  < M; i++){
            cout << num[i] << ", ";
        }
        cout << endl;
    }
    */

    cout << sum << endl;


}



