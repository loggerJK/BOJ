#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1
int wine_num; /* 전체 포도주 개수 */

/* 포도주 양을 저장하는 배열 */
int cost[10000 + 1];

/* DP 배열 */
int dp[10000 + 1][2];

/* 최대값을 반환하는 함수 */
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* n번 포도주를 마셨다고 가정했을 때, n~N까지의 최대 포도주량을 반환 */
int f(int n, int prev_status)
{
    /*  base_case 설정 */

    if (n > wine_num)
    {
        return 0;
    }
    if (dp[n][prev_status] != -1)
    {
        return dp[n][prev_status];
    }

    if (prev_status == true)
    {
        int max_data = 0;
        for (int i = n + 2; i <= wine_num; i++)
        {
            int tmp = max(f(i, false), f(i + 1, false));
            if (max_data < tmp)
            {
                max_data = tmp;
            }
        }
        return dp[n][prev_status] = cost[n] + max_data;
    }

    else if (prev_status == false)
    {
        int max_data = max(f(n + 1, true), f(n + 2, false));
        for (int i = n + 2; i <= wine_num; i++)
        {
            int tmp = max(f(i, false), f(i + 1, false));
            if (max_data < tmp)
            {
                max_data = tmp;
            }
        }
        return dp[n][prev_status] = cost[n] + max_data;
    }
}

int main()
{
    scanf("%d", &wine_num);
    /* 배열 초기화 */
    for (int i = 0; i < 10001; i++)
    {
        dp[i][0] = dp[i][1] = -1;
        cost[i] = 0;
    }
    for (int i = 1; i <= wine_num; i++)
    {
        scanf("%d", &cost[i]);
    }
    printf("%d", max(f(0, true), f(1, false)));
    // printf("%d", f(6, true));

    // system("pause");
}