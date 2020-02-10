#include <stdio.h>
#include <stdlib.h>
#define NUM 101
unsigned long long dp[NUM];
unsigned long long f(unsigned long long N);
int main()
{

    for (int i = 0; i < NUM; i++)
    {
        dp[i] = -1;
    }

    int T = 0, N = 0;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%llu\n", f(N));
    }
    system("pause");
}

unsigned long long f(unsigned long long N)
{
    if (1 <= N && N <= 3)
    {
        return 1;
    }
    else if (4 <= N && N <= 5)
    {
        return 2;
    }
    else
    {
        if (dp[N] != -1)
        {
            return dp[N];
        }

        dp[N] = f(N - 5) + f(N - 1);
        return dp[N];
    }
}