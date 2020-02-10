#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
/* 
cost [N][status]
N번째 집을 status로 칠하는데 필요한 비용을 저장
 */
int cost[MAX][3];
int DP[MAX][3];
int N = 0;
int f(int n, int status);

/* 
최솟값 출력 함수
 */
int min(int a, int b)
{
    if (a > b)
        return b;
    else
    {
        return a;
    }
}
/* 
    DP[n][status] : f(n,status)를 저장하는 DP배열
    Impossibile -1로 초기화


    status 정의
    R = 0
    G = 1
    B = 2
 */

int main()
{
    // DP 초기화
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            DP[i][j] = -1;
        }
    }

    // 집의 수 N 입력
    scanf("%d", &N);

    // cost 배열 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("%d", min(f(1, 0), min(f(1, 1), f(1, 2))));
}

int f(int n, int status)
{
    /* 
    1. base case
    2. DP 검사
    3. 계산
     */

    if (n >= N)
    {
        return cost[n][status];
    }

    if (DP[n][status] != -1)
    {
        return DP[n][status];
    }
    else
    {
        if (status == 0)
            // R인 경우
            return DP[n][status] = cost[n][status] + min(f(n + 1, 1), f(n + 1, 2));
        else if (status == 1)
            // G인 경우
            return DP[n][status] = cost[n][status] + min(f(n + 1, 0), f(n + 1, 2));
        else if (status == 2)
            // B인 경우
            return DP[n][status] = cost[n][status] + min(f(n + 1, 0), f(n + 1, 1));
    }
}