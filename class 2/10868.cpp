#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct deque{
    struct Node *front;
    struct Node *rear;
    int size;
}deque;


void init(deque *d);
int size(deque *d);
int is_empty(deque *d);


void init(deque *d){
    d->front = NULL;
    d->rear = NULL;
    d->size = 0;
}

int size(deque *d){
    return d->size;
}

int is_empty(deque *d){
    if(d->size == 0) return 1;
    else return 0;
}

int front(deque *d){
    if(is_empty(d) == 1) return -1;
    return d->front->data;
}

int back(deque *d){
    if(is_empty(d) == 1) return -1;
    return d->rear->data;
}

void push_front(deque *d, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> next = NULL;
    newNode -> prev = NULL;
    newNode -> data = data;

    if(is_empty(d) == 1){ // 덱이 비었을때
        d-> rear = newNode;
    }
    else{
        newNode -> next = d->front;
        d->front -> prev = newNode;
    }
    d->front = newNode;
    d->size++;
}

void push_back(deque *d, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> next = NULL;
    newNode -> prev = NULL;
    newNode -> data = data;

    if(is_empty(d) == 1){ // 덱이 비었을때
        d-> front = newNode;
    }
    else{
        newNode -> prev = d->rear;
        d->rear -> next = newNode; // 기존의 rear 다음을 새로운 노드로
    }
    d->rear = newNode;
    d->size++;
}

int pop_front(deque *d){
   
    if(d->size == 0){ // 덱이 비어있으면 
        return -1;
    }

    struct Node* temp = d->front;
    int data = temp->data;

    /* 개수가 1개인 경우 */
    if(d->size == 1)
    {    
        d->front = NULL;
        d->rear = NULL;
        d->size--;
        return data;
    }
    else
    {
        d->front = temp -> next;
        d->front-> prev = NULL;
    }
    
    temp -> next = NULL;
    free(temp);
    d->size--;
    return data;
}

int pop_back(deque *d){
    
    if(d->size == 0) return -1;

    struct Node *temp = d->rear;
    int data = temp -> data;
    
    if(d->size == 1){
        d->front = NULL;
        d->rear = NULL;
        d->size--;
        return data;
    }
    else{
        d->rear = temp -> prev;
        d->rear->next = NULL;

    }
    temp->prev =NULL;
    free(temp);
    d->size--;
    return data;
}

int main(){

    deque d;
    int SIZE;
    scanf("%d", &SIZE);

    char order[10000][12];
    int num[10000];
    int k = 0 ;
    for(int i = 0; i< SIZE; i++){
        scanf("%s", order[i]);
        /* 숫자만 따로 다른 배열에 저장함 */
        if(strcmp(order[i], "push_front")==0){
            scanf("%d", &num[k++]);
        }
        else if(strcmp(order[i], "push_back")==0){
            scanf("%d", &num[k++]);
        }
    }

    k = 0;
    int tmp;
     for(int i = 0; i < SIZE; i++){
        if(strcmp(order[i], "push_front")==0){
            push_front(&d, num[k++]);
        }
        else if(strcmp(order[i], "push_back")==0){
            push_back(&d,num[k++]);
        }
        else if(strcmp(order[i],"front") == 0){
            tmp = front(&d);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "back") == 0){
            tmp = back(&d);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "size") == 0){
            tmp = size(&d);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "empty") == 0){
            tmp = is_empty(&d);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "pop_front")==0){
            tmp = pop_front(&d);
            printf("%d\n", tmp);
        }
        else if(strcmp(order[i], "pop_back")==0){
            tmp = pop_back(&d);
            printf("%d\n", tmp);
        }
    }
}