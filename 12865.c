#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 101

typedef struct
{
    int weight;
    int value;
} obj;

int N = 0;      /* 물품의 총 개수 */
int K = 0;      /* 최대 무게 */
obj data[size]; /* 번호 / 무게 / 가치 */
int dp[100000 + 1][size];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int f(int k, int n)
{
    /* base case */
    if (k <= 0 || n <= 0)
        return 0;
    if (n == 1)
    {
        if (k >= data[n].weight)
            return data[n].value;
        else
            return 0;
    }
    /* DP 검사 */
    if (dp[k][n] != -1)
        return dp[k][n];
    /* 계산 */
    if (k >= data[n].weight)
    {
        dp[k][n] = max(
            f(k - data[n].weight, n - 1) + data[n].value,
            f(k, n - 1));
    }
    else
    {
        dp[k][n] = f(k, n - 1);
    }

    return dp[k][n];
}

int main()
{
    /* 배열 초기화 */
    for (int i = 0; i < 100001; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dp[i][j] = -1;
        }
    }
    scanf("%d %d", &N, &K);
    /* 인풋 데이터 입력 */
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &data[i].weight, &data[i].value);
    }

    printf("%d", f(K, N));
}