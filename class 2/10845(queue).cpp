#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Queue{
    struct Node* front;
    struct Node* rear;
    int count;
}Queue;

void init(Queue *q);
int size(Queue *q);
int is_empty(Queue *q);

void init(Queue *q){
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int size(Queue *q){
    return q->count;
}

int is_empty(Queue *q){
    if(q->count == 0) return 1;
    else return 0;
}

int front(Queue *q){
    if(is_empty(q) == 1) return -1;
    return q->front->data;
}

int back(Queue *q){
    if(is_empty(q) == 1) return -1;
    return q->rear->data;
}

void push(Queue *q, int data){
    
    // 새로운 노드를 먼저 생성함.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> next = NULL;
    newNode -> data = data;

    if(is_empty(q) == 1){ // 큐가 비어있을때
        q->front = newNode;
    }
    else{ // 큐가 비어있지 않을때
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->count++;
}

int pop(Queue *q){

    if(is_empty(q) == 1) return -1;

    struct Node *temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    q->count--;
    return data;
}

int main(){
    Queue q;
    int SIZE;
    scanf("%d", &SIZE);

    char order[2000000][14];
    int num[SIZE];
    int k = 0;
    for(int i = 0; i < SIZE; i++){
        scanf("%s", order[i]);
        if(strcmp(order[i], "push")==0){
            scanf("%d", &num[k++]);
        }
    }

    k = 0;
    int tmp;
    for(int i = 0; i < SIZE; i++){
        if(strcmp(order[i], "push")==0){
            push(&q, num[k++]);
        }
        else if(strcmp(order[i], "front")==0){
            tmp = front(&q);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "back") == 0){
            tmp = back(&q);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "size") == 0){
            tmp = size(&q);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "empty") == 0){
            tmp = is_empty(&q);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "pop")==0){
            tmp = pop(&q);
            printf("%d\n", tmp);
        }
    }


}
