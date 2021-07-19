/*
https://www.acmicpc.net/problem/1655
가운데를 말해요
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 1000001

int N;

typedef struct
{
    void **heapAry; /* 데이터를 저장할 void* 배열 */
    int last;       /* 마지막 idx */
    int size;       /* data size */
    int (*compare)(void *argu1, void *argu2);
    int maxSize;
} HEAP;
/* 자료형에 따라서 다르게 작성 */
int _compare(void *argu1, void *argu2)
{
    /* int형이라고 가정한다 */
    int data1 = *(int *)argu1;
    int data2 = *(int *)argu2;

    if (data1 > data2)
        return 1;
    else if (data1 == data2)
        return 0;
    else
        return -1;
}

HEAP *createHeapMin(int maxSize, int (*compare)(void *argu1, void *argu2))
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    if (!heap) /* NULL이라면 */
        return NULL;
    /* 어차피 last + 1 = size의 관계일텐데 */
    heap->last = -1;
    heap->size = 0;
    /* void*가 가리키는 데이터의 크기 비교를 위해 함수 포인터를 사용한다 */
    heap->compare = compare;
    /* 왜하는 겨? */
    heap->maxSize = (int)pow(2, ceil(log2(maxSize))) - 1;
    /* void*가 maxSize만큼 들어가는 메모리 공간을 할당한다 */
    heap->heapAry = (void **)calloc(heap->maxSize, sizeof(void *));
    return heap;
}
void reheapUpMin(HEAP *heap, int idx)
{
    if (idx <= 0 || idx >= heap->size)
        /* 0이라면 루트에 있는 것이다.
        0미만 혹은 size 이상이라면 접근이 불가능 */
        return;

    int parent_idx = (idx - 1) / 2;

    if (heap->compare(heap->heapAry[parent_idx], heap->heapAry[idx]) > 0)
    {
        /* 둘의 데이터를 바꾼다 */
        /* 힙 영역에 메모리가 보존되므로 화살표(포인터)만 바꿔도 충분 */
        void *temp;
        temp = heap->heapAry[parent_idx];
        heap->heapAry[parent_idx] = heap->heapAry[idx];
        heap->heapAry[idx] = temp;
        reheapUpMin(heap, parent_idx);
        return;
    }
}

void reheapDownMin(HEAP *heap, int idx)
{
    /* 자식 노드 중 큰 것을 찾자
    1. 자식이 없을 경우
    2. 왼쪽 자식만 있을 경우
    3. 둘 다 있을 경우 */

    int minchildLoc = 0;
    int leftchildLoc = 2 * idx + 1;
    int rightchildLoc = 2 * idx + 2;

    if (leftchildLoc > heap->last)
    {
        /* 자식이 없는 경우다.
        힙다운할 필요 없음 */
        return;
    }
    else if (leftchildLoc == heap->last)
    {
        /* 왼쪽 자식만 있는 경우 */
        if (heap->compare(heap->heapAry[idx], heap->heapAry[leftchildLoc]) > 0)
        {
            /* 부모 >왼쪽 자식이면 swap*/
            void *tmp = heap->heapAry[idx];
            heap->heapAry[idx] = heap->heapAry[leftchildLoc];
            heap->heapAry[leftchildLoc] = tmp;
            reheapDownMin(heap, leftchildLoc);
        }
    }
    else
    {
        /* 둘 다 있는 경우 */
        if ((heap->compare(heap->heapAry[rightchildLoc], heap->heapAry[leftchildLoc]) < 0))
            minchildLoc = rightchildLoc;
        else
        {
            minchildLoc = leftchildLoc;
        }
        if (heap->compare(heap->heapAry[idx], heap->heapAry[minchildLoc]) > 0)
        {
            /* 부모 > 자식이면 swap*/
            void *tmp = heap->heapAry[idx];
            heap->heapAry[idx] = heap->heapAry[minchildLoc];
            heap->heapAry[minchildLoc] = tmp;
            reheapDownMin(heap, minchildLoc);
        }
    }
}
bool heapInsertMin(HEAP *heap, void *dataPtr)
{
    /* maxSize를 초과하게 될 경우 false */
    if (heap->size >= heap->maxSize)
        return false;
    /* Heap 사이즈 증가 */
    heap->last++;
    heap->size++;
    /* 데이터 insert */
    // void *save_data_ptr = (void *)malloc(sizeof(void *));
    // *save_data_ptr = *dataPtr;
    heap->heapAry[heap->last] = dataPtr;

    reheapUpMin(heap, heap->last);
    return true;
}

bool heapDeleteMin(HEAP *heap, void **dataOutPtr)
{
    if (heap->size == 0)
        return false;
    /* 모든 heapDelete는 루트 삭제다 */
    *dataOutPtr = heap->heapAry[0]; /* 삭제할 루트 데이터 */
                                    /* 루트를 last로 대체한다 */
    heap->heapAry[0] = heap->heapAry[heap->last];
    heap->last--;
    heap->size--;

    reheapDownMin(heap, 0);

    return true;
}
HEAP *createHeapMax(int maxSize, int (*compare)(void *argu1, void *argu2))
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    if (!heap) /* NULL이라면 */
        return NULL;
    /* 어차피 last + 1 = size의 관계일텐데 */
    heap->last = -1;
    heap->size = 0;
    /* void*가 가리키는 데이터의 크기 비교를 위해 함수 포인터를 사용한다 */
    heap->compare = compare;
    /* 왜하는 겨? */
    heap->maxSize = (int)pow(2, ceil(log2(maxSize))) - 1;
    /* void*가 maxSize만큼 들어가는 메모리 공간을 할당한다 */
    heap->heapAry = (void **)calloc(heap->maxSize, sizeof(void *));
    return heap;
}
void reheapUpMax(HEAP *heap, int idx)
{
    if (idx <= 0 || idx >= heap->size)
        /* 0이라면 루트에 있는 것이다.
        0미만 혹은 size 이상이라면 접근이 불가능 */
        return;

    int parent_idx = (idx - 1) / 2;

    if (heap->compare(heap->heapAry[parent_idx], heap->heapAry[idx]) < 0)
    {
        /* 둘의 데이터를 바꾼다 */
        /* 힙 영역에 메모리가 보존되므로 화살표(포인터)만 바꿔도 충분 */
        void *temp;
        temp = heap->heapAry[parent_idx];
        heap->heapAry[parent_idx] = heap->heapAry[idx];
        heap->heapAry[idx] = temp;
        reheapUpMax(heap, parent_idx);
        return;
    }
}

void reheapDownMax(HEAP *heap, int idx)
{
    /* 자식 노드 중 큰 것을 찾자
    1. 자식이 없을 경우
    2. 왼쪽 자식만 있을 경우
    3. 둘 다 있을 경우 */

    int maxchildLoc = 0;
    int leftchildLoc = 2 * idx + 1;
    int rightchildLoc = 2 * idx + 2;

    if (leftchildLoc > heap->last)
    {
        /* 자식이 없는 경우다.
        힙다운할 필요 없음 */
        return;
    }
    else if (leftchildLoc == heap->last)
    {
        /* 왼쪽 자식만 있는 경우 */
        if (heap->compare(heap->heapAry[idx], heap->heapAry[leftchildLoc]) < 0)
        {
            /* 부모 < 왼쪽 자식이면 swap*/
            void *tmp = heap->heapAry[idx];
            heap->heapAry[idx] = heap->heapAry[leftchildLoc];
            heap->heapAry[leftchildLoc] = tmp;
            reheapDownMax(heap, leftchildLoc);
        }
    }
    else
    {
        /* 둘 다 있는 경우 */
        if ((heap->compare(heap->heapAry[rightchildLoc], heap->heapAry[leftchildLoc]) > 0))
            maxchildLoc = rightchildLoc;
        else
        {
            maxchildLoc = leftchildLoc;
        }
        if (heap->compare(heap->heapAry[idx], heap->heapAry[maxchildLoc]) < 0)
        {
            /* 부모 < 자식이면 swap*/
            void *tmp = heap->heapAry[idx];
            heap->heapAry[idx] = heap->heapAry[maxchildLoc];
            heap->heapAry[maxchildLoc] = tmp;
            reheapDownMax(heap, maxchildLoc);
        }
    }
}
bool heapInsertMax(HEAP *heap, void *dataPtr)
{
    /* maxSize를 초과하게 될 경우 false */
    if (heap->size >= heap->maxSize)
        return false;
    /* Heap 사이즈 증가 */
    heap->last++;
    heap->size++;
    /* 데이터 insert */
    // void *save_data_ptr = (void *)malloc(sizeof(void *));
    // *save_data_ptr = *dataPtr;
    heap->heapAry[heap->last] = dataPtr;

    reheapUpMax(heap, heap->last);
    return true;
}

bool heapDeleteMax(HEAP *heap, void **dataOutPtr)
{
    if (heap->size == 0)
        return false;
    /* 모든 heapDelete는 루트 삭제다 */
    *dataOutPtr = heap->heapAry[0]; /* 삭제할 루트 데이터 */
                                    /* 루트를 last로 대체한다 */
    heap->heapAry[0] = heap->heapAry[heap->last];
    heap->last--;
    heap->size--;

    reheapDownMax(heap, 0);

    return true;
}

int main()
{

    HEAP *maxheap = createHeapMax(SIZE, _compare);
    HEAP *minheap = createHeapMin(SIZE, _compare);

    int N = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {

        /* 데이터 입력 */
        int inputData = 0;
        scanf("%d", &inputData);

        /* 각각의 heap에서 delete 시행*/
        /* 나중에 원상복구 필수 */
        void *maxHeapTopPtr = NULL;
        void *minHeapTopPtr = NULL;
        int maxheapTop = 0;
        int minheapTop = 0;
        int median = 0;

        /* 1. 크기 조건을 고려하여 Insert */
        if (maxheap->size == minheap->size)
        {
            heapDeleteMax(maxheap, &maxHeapTopPtr);
            if (!maxHeapTopPtr)
            {
                /* 만약 maxHeap에 아무것도 없다면 maxHeap에 insert */
                int *inputPtr = (int *)malloc(sizeof(int));
                *inputPtr = inputData;
                heapInsertMax(maxheap, inputPtr);
                median = inputData;
                printf("%d\n", median);
                continue;
            }
            else
            {
                maxheapTop = *(int *)maxHeapTopPtr;
            }
            if (heapDeleteMin(minheap, &minHeapTopPtr))
            {
                minheapTop = *(int *)minHeapTopPtr;
            }

            /* iinputdata를 삽입했다고 가정하고 중간값을 계산한다 */
            if (inputData <= maxheapTop)
                median = maxheapTop;
            else if (inputData <= minheapTop)
                median = inputData;
            else
                median = minheapTop;

            /* inputData를 케이스를 고려하여 삽입한다. */
            /* 맨 처음에 초기화를 어떻게 할 것인지 고려해야 함 */
            if (inputData <= minheapTop)
            {
                /* inputData를 maxheap에 insert */
                int *inputPtr = (int *)malloc(sizeof(int));
                *inputPtr = inputData;
                heapInsertMax(maxheap, inputPtr);
                /* 원상복구 
                maxHeapTop을 maxHeap에 insert
                minHeapTop을 minHeap에 insert
                */
                heapInsertMax(maxheap, maxHeapTopPtr);
                heapInsertMin(minheap, minHeapTopPtr);
            }
            else
            {
                /* 
                원상 복구 시행
                maxHeapTop을 maxHeap에 insert
                minheapTop을 maxheap에 insert
                inputData를 minheap에 insert */
                heapInsertMax(maxheap, maxHeapTopPtr);
                heapInsertMax(maxheap, minHeapTopPtr);
                int *inputDataPtr = (int *)malloc(sizeof(int));
                *inputDataPtr = inputData;
                heapInsertMin(minheap, inputDataPtr);
            }
        }
        else
        { /* maxheap size = minheap size + 1 인 case */
            heapDeleteMax(maxheap, &maxHeapTopPtr);
            if (!maxHeapTopPtr)
            { /* 삭제 실패 */
                /* 만약 maxHeap에 아무것도 없다면 maxHeap에 insert */
                int *inputPtr = (int *)malloc(sizeof(int));
                *inputPtr = inputData;
                heapInsertMax(maxheap, inputPtr);
                median = inputData;
                printf("%d\n", median);
                continue;
            }
            else
            {
                maxheapTop = *(int *)maxHeapTopPtr;
            }
            if (heapDeleteMin(minheap, &minHeapTopPtr))
            {
                minheapTop = *(int *)minHeapTopPtr;
            }

            if (inputData < maxheapTop)
            {

                /* inputData는 maxheap에 insert */
                int *inputPtr = (int *)malloc(sizeof(int));
                *inputPtr = inputData;
                heapInsertMax(maxheap, inputPtr);

                /* maxHeapTop을 minheap에 insert 
                 minheapTop을 minheap에 insert*/
                heapInsertMin(minheap, maxHeapTopPtr);
                if (minHeapTopPtr)
                    heapInsertMin(minheap, minHeapTopPtr);

                /*median 계산 */
                void *pOut = NULL;
                heapDeleteMax(maxheap, &pOut);
                median = *(int *)pOut;
                heapInsertMax(maxheap, pOut); /*  원상복구 */
            }
            else
            { /* input >= maxTop인 case */
                median = maxheapTop;

                /* 원상복구 
                maxHeapTop maxeheap
                minHeapTop minheap
                inputdata minheap
                */
                heapInsertMax(maxheap, maxHeapTopPtr);
                if (minHeapTopPtr)
                    heapInsertMin(minheap, minHeapTopPtr);
                int *inputPtr = (int *)malloc(sizeof(int));
                *inputPtr = inputData;
                heapInsertMin(minheap, inputPtr);
            }
        }

        /* 중간값 출력 */

        printf("%d\n", median);
    }
}