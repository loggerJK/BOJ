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
long long dp[MAX][2]; // f(N) DP용 배열
long long f(long long n, int prev_status);
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
        dp[i][0] = dp[i][1] = -1; /* f(n)으로 impossible한 value */
    }

    /* f(0) 게산 */
    printf("%lld", f(0, 0));
    // system("pause");
}

long long f(long long n, int prev_status)
{
    /* 

    1. base case
    2. dp 검사
    3. 계산
     */

    /* base case check */

    if (n == 0)
    {
        return max(
            f(1, 0),
            f(2, 0));
    }
    if (n == N)
    {
        return dp[n][prev_status] = score[n];
    }
    else if (n == N - 1)
    {
        return dp[n][prev_status] = score[n] + f(N, 1);
    }
    else if (n == N - 2)
    {
        return dp[n][prev_status] = score[n] + f(N, 0);
    }

    /* DP array check */

    else if (dp[n][prev_status] != -1)
    {
        return dp[n][prev_status];
    }

    /* 실제 계산  */
    else if (prev_status == 0)
    {
        dp[n][prev_status] = score[n] + max(f(n + 1, 1), f(n + 2, 0));
        return dp[n][prev_status];
    }
    else if (prev_status == 1)
    {
        dp[n][prev_status] = score[n] + f(n + 2, 0);
        return dp[n][prev_status];
    }
}