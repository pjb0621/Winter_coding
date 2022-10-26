/*
https://blog.naver.com/PostView.naver?blogId=kks227&logNo=220781402507&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=12&postListTopCurrentPage=1&from=postList&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=12
insert(k, value)
erase(k)
함수를 스스로 만들어보자

*/

#include <iostream>
#include <cstdlib>
using namespace std;

class InvalidIndexException{};

template<typename T>
class ListNode{
public:
    T value;
    ListNode<T> *next; 

    // constructor
    ListNode<T>(): next(nullptr){}
    ListNode<T>(T value1, ListNode<T> *next1): value(value1), next(next1);

};

/*
연결 리스트에 필요한 요소는

1. 노드
2. 헤드 노드를 가리키는 포인터
3. 노드의 개수를 나타내는 size
4. 노드 위치를 가리킬수있는 임시 포인터(함수 제작시 사용)

*/

template <typename T>
class LinkedList{
public:
    int size;
    ListNode<T> *head;

    // 생성자
    LinkedList<T>(): size(0), head(nullptr){}

    // 소멸자
    ~LinkedList<T>(){
        ListNode<T> *t1 = head, *t2;
        while(t1 != nullptr){ // 맨앞에있는 노드를 없애는 것임
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }

    // 멤버함수
    void insert(int k, T value){ // k번쨰 원소 앞에 새 원소 삽입
    // k번째 노드까지는 접근해야함.
    // 노드를 새로운 노드하나랑
    // 임시 포인터 하나를 만들어서
    // tmp = node->next;
    // 반복하자

    try{
        if (k<0 || k > size) throw InvalidIndexException();

        if(k == 0){
            head = new ListNode<T>(value,head);
        }
        else{
            ListNode<T> *dest = head; //listNode 타입의 포인터를 만들어서, head 가리키게 함. 
            for(int i=0; i<k-1; i++) dest = dest->next; // k-1번째 노드 까지 이동
            dest->next = new ListNode<T>(value, dest->next); // k번째 자리에 노드 생성
        }
        size++;

    }
    catch(InvalidIndexException e){
        cerr << "잘못된 인덱스입니다." << endl;
        exit(1);
    }
    }

    void erase(int k){
        try{
            // 예외 처리 : 잘못된 인덱스
            if(k < 0 || k >= size) throw InvalidIndexException();

            if(k == 0){ // head 삭제
                ListNode<T> *dest = head->next;
                delete head; // 포인터이므로 삭제는 delete 
                head = dest;
            }
            else{ //k번째 원소 삭제
                ListNode<T> *dest = head; *temp;
                for(int i = 0; i <k-1; i++) dest = dest->next; // k-1번째 노드까지 옴
                // k번재 노드를 삭제하면 k-1번쨰 노드의 다음이 k번째 노드의 다음임
                temp = dest -> next -> next;
                delete dest->next;
                dest->next = temp;
            
            }
            size--;
        }
        catch(InvalidIndexException e){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(2);
        }
    }


}