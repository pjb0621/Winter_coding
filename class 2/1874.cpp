#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

typedef struct Stack{
    int size;
    struct Node *top;
}Stack;

void init(Stack *s){
    s->size = 0;
    s->top = NULL;
}

int size(Stack *s){
    return s->size;
}


int top(Stack *s){
    if(s->size == 0) return -1;
    else return s->top->data;
}

void push(Stack *s, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = s->top;

    s->top = newNode;
    s->size++;
}

void pop(Stack *s){ // 빠진 원소를 출력함. 

    if(s->size == 0) return;

    struct Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
}


int main(){

    int n;
    cin >> n;
    int num[n];
    char stack_sequence[1000000];
    int k = 0;
    Stack s;
    init(&s);

    for(int i = 0; i < n ; i++){
        cin >> num[i];
    }

    /* 수열의 원소를 비교해서 push, pop 결정. 
        top의 원소가 NULL이면 push(1부터 시작)
        만약 top == 수열의 원소이면 다음 cycle로 넘어가고 '-' 기호 stack_sequence에 저장 
        top != 수열의 원소이면 
        top이 수열의 원소보다 작으면 push하기.
        top이 수열의 원소보다 크면 NO 출력후 RETURN;
    */

    int number = 1;
    int seq_idx = 0;
    bool end = false;
    for(int i = 0; i < n ; i++){
        int x = num[i];
        while(1){
            if(top(&s) == -1){ // top == NULL
                push(&s, number++);
                stack_sequence[seq_idx++] = '+';
            }
            else if(top(&s) == x) // 수열 원소가 top가 일치하면
            {
                stack_sequence[seq_idx++] = '-';
                pop(&s);
                break;
            }
            else if(top(&s) != x){ // 수열 원소가 top과 일치하지 않을떄.
                if(top(&s) < x){ // top < 수열 원소
                    push(&s, number++);
                    stack_sequence[seq_idx++] = '+';
                }
                if(top(&s) > x){ // top > 수열 원소 
                    end = true;
                    break;
                }              
            }
        }

        if(end) break;
    }

    if(end){
        cout << "NO" <<endl;
        return 0;
    }
    else{
        for(int i = 0; stack_sequence[i] != '\0'; i++){
            cout << stack_sequence[i] << '\n';
        }
    }
    
}