/* 
https://www.acmicpc.net/problem/2565
전깃줄 문제
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define max_edge 101
#define max_node 11

/* <정의>
n번 전깃줄 = 시작점이 n인 전깃줄 */

int N = 0; /* 전깃줄 개수 */
/*최초 1회만 실행, n번 전깃줄과 교차하는 전깃줄의 개수를 계산, cross_info정보를 저장, 개수를 return */
void cross_cnt_refresh(int n);
void delete_edge(int n); /* n번 전깃줄을 삭제하고 cross_cnt 갱신 */
int max_compare(int a, int b);
int cross_cnt[max_node];             /* n번 전깃줄과 교차하는 전깃줄의 개수 */
int edge[max_node];                  /* edge[n] n번 전깃줄이 연결된 전깃줄 번호를 return. 전깃줄이 없으면 -1.*/
bool cross_info[max_node][max_node]; /* cross_info[n][k] n번 전깃줄과 k번 전깃줄이 교차하는지 여부 */
int delete_cnt = 0;

void cross_cnt_refresh(int n)
{
    /* 자기 자신의 전깃줄이 없다면 교차개수는 없다 */
    if (edge[n] == -1)
    {
        cross_cnt[n] = 0;
        return;
    }

    for (int i = 1; i <= max_node - 1; i++)
    {

        /* 자기 자신의 전깃줄 or 무간선은 계산에서 제외 */
        if (i == n || edge[i] == -1)
            continue;

        if (i < n)
            if (edge[n] < edge[i])
            {
                cross_cnt[n]++;
                cross_info[n][i] = cross_info[i][n] = true;
            }

        if (i > n)
            if (edge[n] > edge[i])
            {
                cross_cnt[n]++;
                cross_info[n][i] = cross_info[i][n] = true;
            }
    }
}

int max_compare(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void delete_edge(int n)
{
    delete_cnt++;
    /* edge 삭제 */
    edge[n] = -1;
    /* 자기자신의 교차개수는 사라진다 */
    cross_cnt[n] = 0;
    /* 교차하는 전깃줄들의 교차개수를 1씩 감소시키고, 교차정보를 삭제한다 */
    for (int k = 1; k <= max_node - 1; k++)
    {
        if (cross_info[n][k])
        {
            cross_cnt[k]--;
            cross_info[n][k] = cross_info[k][n] = false;
        }
    }
}

int main()
{
    /* 배열 초기화 */
    for (int i = 0; i < max_node; i++)
    {
        cross_cnt[i] = 0;
        edge[i] = -1;
        for (int j = 0; j < max_node; j++)
        {

            cross_info[i][j] = false;
        }
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
        edge[x] = y;
    }
    /* 모든 전깃줄의 교차 개수를 검사한다 */
    for (int i = 1; i <= max_node - 1; i++)
    {
        cross_cnt_refresh(i);
    }

    while (true)
    {
        int max = cross_cnt[1];
        /* 모든 전깃줄의 교차 개수를 점검한다 O(n)*/
        for (int i = 1; i <= max_node - 1; i++)
            max = max_compare(max, cross_cnt[i]);

 
        if (max == 0)
            break;

        int max_idx = 1; /* 교차점의 개수가 가장 많은 전깃줄 번호 O(n) */
        /* 갱신 */
        for (int i = 1; i <= max_node - 1; i++)
            if (cross_cnt[max_idx] < cross_cnt[i])
                max_idx = i;
        printf("--------------------\n");
        for (int i = 1; i <= max_node - 1; i++)
            printf("cross_cnt]%d] = %d\n", i, cross_cnt[i]);
        printf("delete_cnt = %d\n", delete_cnt);
        printf("max = %d\n", max);
        printf("max_idx = %d\n", max_idx);

        delete_edge(max_idx);
    }

    printf("%d", delete_cnt);
}
