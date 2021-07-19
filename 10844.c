/* 
https://www.acmicpc.net/problem/10844
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* dp[n][k]]
    맨 앞자리가 k인, n자리 수의 개수
 */
int dp[101][10];

bool compare(int a, int b)
{
    int data = abs(a - b);
    if (data == 1)
        return true;
    else
    {
        return false;
    }
}
bool func(int K)
{
    if (1 <= K && K <= 9)
        return true;

    if (dp[K] != -1)
        return dp[K];

    int n_100 = K / 10 % 10;
    int n_10 = K % 10;
    if (compare(n_100, n_10))
    {
        return dp[K] = func(K / 10);
    }
    else
        return dp[K] = false;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    /* N자리 수는 10자리 단위로 끊어서 검사한다 */
}