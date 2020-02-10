#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 1000000

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

HEAP *createHeap(int maxSize, int (*compare)(void *argu1, void *argu2))
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
void reheapUp(HEAP *heap, int idx)
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
            reheapDown(heap, leftchildLoc);
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
            reheapDown(heap, minchildLoc);
        }
    }
}
bool heapInsert(HEAP *heap, void *dataPtr)
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

    reheapUp(heap, heap->last);
    return true;
}

bool heapDelete(HEAP *heap, void **dataOutPtr)
{
    if (heap->size == 0)
        return false;
    /* 모든 heapDelete는 루트 삭제다 */
    *dataOutPtr = heap->heapAry[0]; /* 삭제할 루트 데이터 */
                                    /* 루트를 last로 대체한다 */
    heap->heapAry[0] = heap->heapAry[heap->last];
    heap->last--;
    heap->size--;

    reheapDown(heap, 0);

    return true;
}

int main()
{
    HEAP *heap = createHeap(100000, _compare);
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
            }
            // free(real_out);
        }
        else
        {
            heapInsert(heap, tmp);
        }
    }
}