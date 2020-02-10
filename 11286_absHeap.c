#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
    void **heapAry;
    int size;
    int last;
    int maxSize;
    int (*compare)(void *argu1, void *argu2);
} HEAP;
int abs_min_compare(void *argu1, void *argu2)
{
    /* int형이라고 가정한다 */
    int abs_data1 = abs(*(int *)argu1);
    int abs_data2 = abs(*(int *)argu2);
    int data1 = *(int *)argu1;
    int data2 = *(int *)argu2;

    if (abs_data1 < abs_data2)
        return 1;
    else if (abs_data1 == abs_data2)
        /* 실제 값으로 다시 한번 비교한다 */
        if (data1 < data2)
            return 1;
        else if (data1 == data2)
            return 0;
        else 
            return -1;
    else
        return -1;
}

/* MaxHeap Compare를 기준으로 작성된 MaxHeap 함수이다 */
/* compare 함수를 바꾸면 minHeap으로 바꿀 수 있다 */
HEAP *createHeap(int maxSize, int (*compare)(void *argu1, void *argu2))
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    heap->size = 0;
    heap->last = -1;
    heap->maxSize = pow(2, ceil(log2(maxSize))) - 1;
    heap->compare = compare;
    heap->heapAry = (void**) calloc(heap->maxSize,sizeof(void*));
    return heap;
}

void reheapUp(HEAP *heap, int idx)
{
    if (idx <= 0 || idx >= heap->size)
        return;

    int parent_idx = (idx - 1) / 2;
    if (heap->compare(heap->heapAry[parent_idx], heap->heapAry[idx]) < 0)
    {
        /* 만약 자식이 더 크다면 올린다 */
        void *tmp = NULL;
        tmp = heap->heapAry[parent_idx];
        heap->heapAry[parent_idx] = heap->heapAry[idx];
        heap->heapAry[idx] = tmp;
        /* 그 후에도 rehepUp조건 을 검사해야 한다 */
        reheapUp(heap, parent_idx);
        return;
    }
}

void reheapDown(HEAP *heap, int idx)
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
            reheapDown(heap, leftchildLoc);
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
            reheapDown(heap, maxchildLoc);
        }
    }
}

bool heapInsert(HEAP *heap, void *pData)
{
    if (heap->last >= heap->maxSize)
        return false;

    heap->last++;
    heap->size++;
    heap->heapAry[heap->last] = pData;

    reheapUp(heap, heap->last);
    return true;
}

bool heapDelete(HEAP *heap, void **dataOutPtr)
{
    if (heap->size == 0)
        return false;

    *dataOutPtr = heap->heapAry[0];
    heap->heapAry[0] = heap->heapAry[heap->last];
    heap->last--;
    heap->size--;

    reheapDown(heap, 0);

    return true;
}

int main()
{
    HEAP *heap = createHeap(100000, abs_min_compare);
    int N = 0;
    scanf("%d", &N); /* 연산의 개수 */

    for (int i = 0; i < N; i++)
    {
        int *tmp = (int *)malloc(sizeof(int));
        scanf("%d", tmp);
        if ((*tmp) == 0)
        {
            void *real_out;
            bool chk = heapDelete(heap, &real_out);
            if (chk == false)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", *(int *)real_out);
                free(real_out);
            }
        }
        else
        {
            heapInsert(heap, tmp);
        }
    }
}
