#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define max_edge 101
#define max_node 501
int N;
int data[max_node];
int dp[max_node];

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
int max(int a, int b)
{
    if (a > b)
        return a;
    else
    {
        return b;
    }
}

/*  n열에서 시작하는 증가부분수열의 최대 길이*/
int f(int n)
{
    if (data[n] == -1)
        return -1;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    Queue *queue = createQueue();

    /* n번째 숫자보다 큰 숫자들의 index를 queue한다 */
    for (int i = n + 1; i <= max_node - 1; i++)
    {
        if (data[n] < data[i])
        {
            int *idxPtr = (int *)malloc(sizeof(int));
            *idxPtr = i;
            push(queue, idxPtr);
        }
    }
    if (queue->count == 0)
    {
        /* n번째 수보다 큰 수가 존재하지 않는다면, n번째 수는 그 자체로 길이 1인 증가수열이다. */
        dp[n] = 1;
        return dp[n];
    }
    else if (queue->count == 1)
    {
        /* n번째 수보다 큰 수가 오직 하나 존재한다면, f(n) =2 */
        return dp[n] = 2;
    }
    else if (queue->count >= 2)
    {
        /* n보다 큰 수가 여러개 존재한다면
        그중에서 f(k)값이 가장 큰 k를 찾는다 */
        int *max_idxPtr = (int *)pop(queue);
        while (queue->count > 0)
        {
            int *dataPtr = (int *)pop(queue);
            if (f(*max_idxPtr) < f(*dataPtr))
            {
                *max_idxPtr = *dataPtr;
            }
        }
        dp[n] = 1 + f(*max_idxPtr);
        return dp[n];
    }
}
int main()
{
    for (int i = 0; i < max_node; i++)
    {
        data[i] = dp[i] = -1;
    }
    /* 전깃줄 개수 입력 */
    scanf("%d", &N);

    /* N번에 걸쳐 전깃줄 초기화, init */
    for (int i = 0; i < N; i++)
    {
        int x = 0;
        int y = 0;
        scanf("%d", &x);
        scanf("%d", &y);
        data[x] = y;
    }

    int max = f(max_node - 1);
    for (int i = max_node - 1; i >= 1; i--)
    {
        if (max < f(i))
            max = f(i);
    }
    // for (int i = 0; i <= 10; i++)
    // {
    //     printf("f(%d) = %d\n", i, f(i));
    // }

    printf("%d", N - max);
}