/* 
https://www.acmicpc.net/problem/10844
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define X 1000000000

long long f_dp[101][10];
long long g_dp[101];
long long f(long long n, long long k);
long long g(long long n);

long long f(long long n, long long k)
{
    if (n == 0 && k == 1) // f(0,1) = 1; 1로 시작하는 0자릿수는 게산을 위해 1로 고정
        return 1;
    if (n == 1 && k == 0) // f(1,0) = 0;
        return 0;
    if (n == 1 && 1 <= k)
        return 1;
    if (k == 0) // f(1,0) = 0;
        return f(n - 1, 1);
    if (f_dp[n][k] != -1)
        return f_dp[n][k];
    else if (k == 1)
    {
        f_dp[n][k] = f(n - 2, 1) + f(n - 1, k + 1);
        f_dp[n][k] %= X;
        return f_dp[n][k];
    }
    else if (k == 9)
    {
        return f_dp[n][k] = f(n - 1, k - 1);
    }
    else
    {
        f_dp[n][k] = f(n - 1, k - 1) + f(n - 1, k + 1);
        f_dp[n][k] %= X;
        return f_dp[n][k];
    }
}

long long g(long long n)
{

    {
        if (g_dp[n] != -1)
            return g_dp[n];

        g_dp[n] = 0;
        for (long long i = 1; i <= 9; i++)
        {
            g_dp[n] += f(n, i);
            g_dp[n] %= X;
        }
        /* g_dp[n] = f(n - 2, 1) + g(n - 1);
        g_dp[n] %= X;
        for (int i = 2; i <= 8; i++)
        {
            g_dp[n] += f(n - 1, i);
            g_dp[n] %= X;
        }
        g_dp[n] = g_dp[n] % X; */
        return g_dp[n];
    }
}

int main()
{
    // dp 배열 초기화
    for (long long i = 0; i < 101; i++)
    {
        g_dp[i] = -1;
        for (long long j = 0; j < 10; j++)
        {
            f_dp[i][j] = -1;
        }
    }

    int N = 0;
    scanf("%d", &N);
    printf("%lld", g(N));
    // long long i = 3;

    // printf("%lld", f(2, 9));

    // printf("g(%lld) = %lld\n", i, g(i));
    // for (long long i = 1; i <= 100; i++)
    // {
    //     printf("g(%lld) = %lld\n", i, g(i));
    //     for (long long j = 0; j < 10; j++)
    //     {
    //         printf("f(%lld, %lld) = %lld\n", i, j, f(i, j));
    //     }
    // }

    // printf("%d", g(100));
    // system("pause");
}
