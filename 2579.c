/* 
https://www.acmicpc.net/problem/2579
계단의 개수 1 <= N <= 300
게단의 점수 <= 10000, 자연수
총 점수의 최댓값을 출력하라

****모든 배열은 0을 제외하고 1부터 사용하는 것을 원칙으로 한다
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 301

long long N = 0;      // 계단의 개수 N
long long score[MAX]; // 계단 점수 기록용 배열
long long dp[MAX];    // f(N) DP용 배열
long long f(long long n, bool visit[MAX]);
long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    bool visit[MAX]; // 방문 기록용 배열
    //계단 개수 입력
    scanf("%d", &N);
    // 점수 입력
    for (long long i = 0; i <= N; i++)
    {
        score[i] = 0;
    }
    for (long long i = 1; i <= N; i++)
    {
        scanf("%d", &score[i]);
    }

    /* 배열들 기본 값으로 초기화 */

    for (int i = 0; i < MAX; i++)
    {
        dp[i] = -1; /* f(n)으로 impossible한 value */
        visit[i] = false;
    }

    /* f(0) 게산 */
    printf("-------------\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("dp[%d] = %d\n", i, dp[i]);
    }
    printf("-------------\n");
    printf("%lld", f(0, visit));
    system("pause");
}

long long f(long long n, bool visit[MAX])
{
    /* 
    0. 방문 처리 && 방문 검사
    1. base case
    2. dp 검사
    3. 계산
     */
    if (n == 0)
    {
        return max(f(1, visit), f(2));
    }
    visit[n] = true;
    /* 3번 연속 방문을 하려고 한다면 0을 리턴한다. */
    if (n > 2 && visit[n - 2] == true && visit[n - 1] == true)
    {
        return 0;
    }

    if (n == N)
    {
        return dp[N] = score[n];
    }
    else if (n == N - 1)
    {
        return dp[n] = score[n] + f(N);
    }
    else if (n == N - 2)
    {
        return dp[n] = score[n] + f(N);
    }
    else if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = score[n] + max(f(n + 1), f(n + 2));
        return dp[n];
    }
}