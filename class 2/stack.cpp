/*
스택 공부
https://blog.naver.com/kks227/220781557098

stack에서의 연산 : pop, push
으로 맨 위에서만 연산이 이뤄진다.

만약 스택이 비어있는데, pop이나 top 연산을 하면, 언더플로우라 하여
예기치 않은 연산 취급을 한다. 

스택의 구현은 보통
연결리스트로 구현하는데 그이유는 o(1)의 시간복잡도를  가지기 때문임.

따라서 연결리스트의 특징을 먼저 이해해보자.
연결리스트의 값은 하나하나가 노드를 이루고 있다.

이 노드는 
1) 자신이 보존중인 값
2) 다음 노드를 가리키는 포인터
2개의 멤버 변수를 가진다.

자료구조의 연산은 삽입, 삭제, 순회 이 크게 3가지로 이뤄지는데,

삽입 
1) 기존 두번째 노드의 next 포인터 = 새노드
2) 새노드의 next 포인터 = 기존 세번쨰 노드

삭제
1) 2 3 4중 3번쨰 노드 삭제원하면,
2의 next를 4로 연결함
2) 3번째 노드 제거 
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);

typedef struct{
    struct Node* top;
    int size;
}Stack;

struct Node {
    int data; /* 데이터 */
    struct Node* nextNode; /* 다음 노드를 가리키는 부분 */

};

// top -> ㅁ -> ㅁ-> null 형태
//push는  top이 newNode를 가리키게끔하기.

void init(Stack *s){
    s->top = NULL;
    s->size = 0;
}

bool is_empty(Stack *s){
    return (s->top == NULL);
}

void push(Stack *s, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data= data;
    newNode->nextNode = (s->top); // 기존의 top을 새로운 노드의 next로
    s->top = newNode;  //top이 newNode를 가리킨다
}

int pop(Stack *s){

    if(is_empty(s)){

        return -1;
    }

    // top의 다음노드를 top으로 하고 free 한다
    
    struct Node* temp = s->top;
    int data = s->top->data;
    s->top= s->top->nextNode;
    free(temp);
    return data;

    /*
    블로그
    Node *temp = s->top
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
    */
}

void print_stack(Stack *s)
{
    struct Node* curr = s->top;
    while(curr != NULL){
        printf("%d-> ", curr->data);
        curr = curr->nextNode;
    }
    printf("NULL \n");
}



int main(){
    Stack s;
    init(&s);
    int SIZE;
    scanf("%d", &SIZE);

    vector <string> arr;

    for(int i = 0 ; i < SIZE; i++){
        getline(cin,arr[i]);
    }

    for(int i = 0; i < SIZE; i++){
        string l = arr[i];
        int len = l.size();
        if(len >= 6){ // push x는 최소 길이가 6임
            
        } 

    }


    
    push(&s, 11); print_stack(&s);
    push(&s, 22); print_stack(&s);
    push(&s, 33); print_stack(&s);
    push(&s, 44); print_stack(&s);

    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    return 0;

}





void PrintNodeFrom(struct Node *from){

    /* from이 Null 일 때 까지,
    즉 끝 부분에 도달할 때 까지 출력*/
    while(from){
        printf("노드의 데이터 : %d \n", from->data);
        from = from ->nextNode;
    }
}
/* 새 노드를 만드는 함수*/
struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode-> data = data;
    newNode-> nextNode =NULL;

    return newNode;
}

/* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수*/
struct Node* InsertNode(struct Node* current, int data){
    /* current 노드가 가리키고 있던 다음 노드가 after 이다 */
    struct Node* after = current -> nextNode;

    /*새로운 노드를 생성한다 */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* 새노드에 값을 넣어준다*/
    newNode->data = data;
    newNode->nextNode = after;

    /*current는 이제 newNode를 가리키게 된다*/
    current->nextNode = newNode;

    return newNode;
}

/* 선택한 노드를 파괴하는 함수 */
void DestroyNode(struct Node* destroy, struct Node *head){
    /* 다음 노드를 가리킬 포인터 */
    struct Node *next = head;

    /* head를 파괴하려 한다면 */
    if(destroy == head) {
        free(destroy);
        return;
    }

    /*만일 next가 NUll 이면 종료 */
    // next는 head부터 끝까지 다 뒤져나가면서, destroy 발견시 연결을 끊어버린다고 생각하자
    while(next){
        /* 만일 next 다음 노드가 destroy라면 next가 destroy 앞 노드*/
        if(next->nextNode == destroy) {
            /* 따라서 next의 다음노드는 destroy가 아니라 destroy의 다음 노드가 된다*/
            next ->nextNode = destroy -> nextNode;
        }
        /*next는 다음 노드를 가리킨다*/
        next = next->nextNode;
    }

    free(destroy);

}