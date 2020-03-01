/* https://www.acmicpc.net/problem/1931 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define size_ 100001

typedef struct
{
    int start;
    int end;
    int required;
} node;
node data[size_];
node sortlist[size_];

int N = 0, cnt = 0;

int compare(const void *a, const void *b)
{
    /* 오름차순 정렬 */
    int num1 = ((node *)a)->required;
    int num2 = ((node *)b)->required;
    if (num1 > num2)
        return 1;
    else if (num1 == num2)
        return 0;
    else
        return -1;
}

int main()
{
    for (int i = 0; i < size_; i++)
        data[i].start = data[i].end = -1;

    scanf("%d", &N);
    /* 노드 정보를 초기화한다 */
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &data[i].start, &data[i].end);

    int prev_start = 0;
    int prev_end = 0;
    static int sortingcnt = 0;
    for (int i = 0; i < N; i++) /* 최대 N번 반복 */
    {
        /* 조건을 만족한다면 후보배열에 insert*/

        for (int i = 1; i <= N; i++)
        {
            if (prev_end <= data[i].start)
            {
                data[i].required = data[i].end - prev_end;
                /* 유의미하게 시간이 소요되는 후보들을 insert한다 */
                if (data[i].required >= 0)
                {
                    sortlist[sortingcnt] = data[i];
                    sortingcnt++;
                }
            }
        }
        /* Qsort를 돌려서 required가 가장 작은 노드를 뽑아낸다 */
        qsort(sortlist, sortingcnt, sizeof(node), compare);
        node *Node = &sortlist[0];
        /* 뽑아낸 노드가 유의미한지 검사한다 */
        if (Node->start != prev_start)
        {
            /* prev_end를 노드의 end로 바꾼다 */
            /* 카운트++ */
            cnt++;
            prev_start = Node->start;
            prev_end = Node->end;
            // printf("%d, %d\n", prev_start, prev_end);
        }
        else
        {
            /* 무의미하다면 for문을 탈출한다 */
            break;
        }
        /* sortinglist 및 카운터 초기화 */
        sortingcnt = 0;
    }

    printf("%d", cnt);
}