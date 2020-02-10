/* 
https://www.acmicpc.net/problem/1932
size: 삼각형의 크기, 1 이상 500 이하, 자연수
노드의 정수 : 0 이상, 9999 이하
모든 배열은 0을 제외하고 1부터 사용한다.
<함수 정의>
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 501

/* 입력받은 데이터를 저장하는 배열 */
int data[MAX][MAX];
/* 삼각형 크기 */
int size = 0;
/* DP용 배열 */
int dp[MAX][MAX];

int f_max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* f(n,k) :
 n의 k번 노드에서 시작
 n ~ N 행까지의 최대 합을 return */
int f(int n, int k)
{
    /* base case */
    if (n == size)
    {
        return data[n][k];
        /* 
                int max = -1;
        for (int i = 1; i <= n; i++)
        {
            max = f_max(
                max,
                data[n][i]);
        }
        */
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    else
    {
        dp[n][k] = data[n][k] + f_max(
                                    f(n + 1, k),
                                    f(n + 1, k + 1));
        return dp[n][k];

        /* 
        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            max = f_max(
                data[n][i] + f(n + 1, k),
                data[n][i] + f(n + 1, k + 1));
        }
         */
    }
}

int main()
{

    /* 전역변수 초기화 */
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            dp[i][j] = -1;
            data[MAX][MAX] = -1;
        }
    }
    /* 삼각형 크기 입력 */
    scanf("%d", &size);

    /* 정수 삼각형 정보 입력 */
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    printf("%d", f(1, 1));
}
