#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 1001
#define init -1
/* 
문제 설계
증가수열과 감소 수열을 동시에 고려하는 문제이다.
변수는 증가수열과 감소수열이 겹치는 중간항 Sk 의 k를 이용한다
 */

int max_compare(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int data[SIZE];   // 수열 정보를 저장할 배열
int inc_dp[SIZE]; // inc(k) 값을 저장할 DP 배열
int dec_dp[SIZE]; // dec(k) 값을 저장할 DP 배열
int N;            // 수열의 크기 N을 전역변수로 선언

int inc(int k) /* 1번항부터 k번항까지, 증가수열의 최대 길이를 계산 후 반환 한다 */
{
    if (k == 1)
        return 1;

    // dp 검사
    if (inc_dp[k] != init)
    {
        return inc_dp[k];
    }

    /* 1 < = x < k, data[x] < data[k] 를 만족하는 x 중에서, 최대 inc(x)를 찾는다 
    max는 최대 inc(x) 값을 가리킨다*/
    int max = 0; // 초기화
    for (int x = 1; x < k; x++)
    {
        if (data[x] >= data[k])
            continue;
        else
            max = max_compare(max, inc(x));
    }

    /* 이때, inc(k) = inc(x) + 1 */
    /* dp 배열에 저장한다 */

    return inc_dp[k] = max + 1;
}

int dec(int k) /* k항 ~ 끝항까지, 감소 수열의 최대 길이를 계산 후 반환한다 */
{
    if (k == N) /* 끝항이라면 */
        return 1;

    /* Dp 배열 검사 */
    if (dec_dp[k] != init)
        return dec_dp[k];

    /* k < x <= N, data[k] > data[x] 를 만족하는 x 중에서, 최대 dec(x) 값을 구한다 */
    int max = 0;
    for (int x = N; k < x; x--)
    {
        if (data[k] <= data[x])
            continue;
        max = max_compare(max, dec(x));
    }

    return dec_dp[k] = max + 1;
}

int main()
{
    /* 배열 값 초기화 */
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = init;
        inc_dp[i] = init;
        dec_dp[i] = init;
    }

    /* 수열 크기 N 입력 */
    scanf("%d", &N);

    /* 수열 데이터 입력 */
    /*  index를 1부터 N까지 사용함에 유의한다. */
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &data[i]);
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     printf("inc(%d) = %d\n",i, inc(i));
    // }
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        // printf("inc(%d) = %d, dec(%d) = %d\n", i, inc(i), i, dec(i));
        max = max_compare(max, inc(i) + dec(i) - 1);
    }
    printf("%d", max);
}