#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[41];
int countdp[41][2];
int count(int a, int b);
int zero_cnt = 0;
int one_cnt = 0;

int main()
{
    int N = 0, M = 0;
    scanf("%d", &N);
    // N번 반복한다
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < 41; j++)
        {
            dp[j] = -1;
            countdp[j][0] = countdp[j][1] = -1;
        }

        scanf("%d", &M);

        printf("%d %d\n", count(M, 0), count(M, 1));
    }
}

int count(int a, int b)
{
    if (a == 0 && b == 0)
    {
        return 1;
    }
    if (a == 0 && b == 1)
    {
        return 0;
    }
    if (a == 1 && b == 0)
    {
        return 0;
    }
    if (a == 1 && b == 1)
    {
        return 1;
    }
    if (countdp[a][b] != -1)
    {
        return countdp[a][b];
    }
    else
    {
        countdp[a][b] = count(a - 1, b) + count(a - 2, b);
        return countdp[a][b];
    }
}