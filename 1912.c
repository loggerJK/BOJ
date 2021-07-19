#include <stdio.h>
#include <stdlib.h>
#define size 100001
#define impossible_num 1000000000

int input[size];
int N = 0;
int dp[size];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
    {
        return b;
    }
}

int f(int i)
{
    /* base case */
    if (i == N)
    {
        return input[N];
    }

    /* DP 검사 */
    /* impossible num을 고칠 필요성이 있음 */
    if (dp[i] != impossible_num)
    {
        return dp[i];
    }

    return dp[i] = max(input[i] + f(i + 1), input[i]);
}

int main()
{
    for (int i = 0; i < size; i++)
    {
        input[i] = impossible_num;
        dp[i] = impossible_num;
    }

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &input[i]);
    }

    /* max 값 구하기 */
    int max = f(1);
    for (int i = 1; i <= N; i++)
    {
        int data = f(i);
        if (max < f(i))
            max = f(i);
    }

    printf("%d", max);
}