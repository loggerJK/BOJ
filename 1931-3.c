/* https://www.acmicpc.net/problem/1931 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define size_ 100050

typedef struct
{
    int start;
    int end;
} node;
node data[size_];

int N = 0, cnt = 0;

int compare(const void *a, const void *b)
{
    /* 오름차순 정렬 */
    int num1end = ((node *)a)->end;
    int num2end = ((node *)b)->end;
    int num1start = ((node *)a)->start;
    int num2start = ((node *)b)->start;

    if (num1end > num2end)
        return 1;
    else if (num1end == num2end)
    {
        if (num1start > num2start)
            return 1;
        else if (num1start == num2start)
            return 0;
        else
            return -1;
    }
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

    /* end 기준 으름차순으로 정렬한다 */
    qsort(data, , sizeof(node), compare);
    printf("-----------------------\n");

    for (int i = 1; i <= N; i++)
    {
        printf("%d %d\n", data[i].start, data[i].end);
    }
    int prev_start = 0;
    printf("-----------------------\n");
    int prev_end = 0;
    for (int i = 1; i <= N; i++)
    {
        /* 조건을 만족하면 / 카운트++ / end 조건 수정 */
        if (prev_end <= data[i].start)
        {
            printf("선택 : %d %d\n", data[i].start, data[i].end);
            cnt++;
            prev_end = data[i].end;
        }
    }

    printf("%d", cnt);
}