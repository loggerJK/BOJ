#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    void *dataptr;
    struct node *next;
} Node;

typedef struct queue
{
    int count;
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    // 메모리 생성에 실패한 경우 null을 반환
    if (queue == NULL)
        return NULL;

    // 멤버 초기화
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void push(Queue *queue, void *ptr)
{
    // 노드를 생성한다
    Node *newNode = (Node *)malloc(sizeof(Node));

    // 노드 초기화
    newNode->dataptr = ptr;
    newNode->next = NULL;
    // 노드가 하나도 없다면 front와 rear를 둘 다 연결한다

    if (queue->count == 0)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    // 노드가 존재한다면 rear에 연결한다
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    // 카운트를 올린다
    queue->count++;
    return;
}

void *pop(Queue *queue)
{
    if (queue->count == 0)
        return NULL;

    Node *oldptr = queue->front;
    void *data = queue->front->dataptr;

    queue->front = queue->front->next;
    if (queue->count == 1)
        queue->rear = oldptr->next;

    free(oldptr);
    queue->count--;
    return data;
}

int size(Queue *queue)
{
    return queue->count;
}

void *front(Queue *queue)
{
    if (queue->count == 0)
        return NULL;
    return queue->front->dataptr;
}

void *back(Queue *queue)
{
    if (queue->count == 0)
        return NULL;
    return queue->rear->dataptr;
}

bool empty(Queue *queue)
{
    if (queue->count == 0)
        return true; //True
    else
        return false;
}