/* https://www.acmicpc.net/problem/11399 */

#include <stdio.h>
#include <stdlib.h>

int N = 0;             // 사람의 개수
int P[1005];           //각 사람이 돈을 인출하는데 걸리는 시간
int partial_sum[1005]; /* 부분합을 저장할 배열 */

int comp(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    if (n1 > n2)
        return 1;
    if (n1 < n2)
        return -1;
    else
        return 0;
}
int main()
{
    scanf("%d", &N);

    for (int i = 0; i < 1005; i++)
        P[i] = -1;
    /* 배열을 입력받는다 */
    for (int i = 0; i < N; i++)
        scanf("%d", &P[i]);
    /* 오름차순으로 sorting */
    qsort(P, N, sizeof(int), comp);

    for (int i = 0; i < N; i++)
    {
        /* N번 반복한다 */
        int sum = 0;
        for (int j = 0; j <= i; j++)
            sum += P[j];
        partial_sum[i] = sum;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += partial_sum[i];

    printf("%d", sum);
}