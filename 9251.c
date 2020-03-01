#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* LCS[x][y] 는 x번이 끝자리, y번이 끝자리인 두 수열을 비교, LCS의 길이를 return한다 */
int LCS[1001][1001];
/*  두 문자열을 저장할 배열 */
char str1[1001];
char str2[1001];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int lcs(int x, int y)
{

    /* base case */
    if (x < 0 || y < 0)
    {
        return 0;
    }
    /* DP 검사 */
    /* 베이스 케이스를 먼저 검사하지 않으면 쓰레기 값에 접근할 위험이 있다 */
    if (LCS[x][y] != -1)
    {
        return LCS[x][y];
    }
    /* 점화식 */
    if (str1[x] == str2[y])
    {
        return LCS[x][y] = 1 + lcs(x - 1, y - 1);
    }
    else
    {
        /* 만약 끝자리 문자가 다르다면*/
        return LCS[x][y] = max(lcs(x - 1, y), lcs(x, y - 1));
    }
}

int main()
{
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            LCS[i][j] = -1;
        }
    }

    scanf("%s", str1);
    scanf("%s", str2);

    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    /* 널 문자를 제외해야 하기 때문에 -1을 추가한다 */
    printf("%d", lcs(str1_len - 1, str2_len - 1));
}