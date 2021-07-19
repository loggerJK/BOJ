/* https://www.acmicpc.net/problem/1541 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /* 문자열을 담을 배열 선언 */
    char array[60];
    char *minustoken[60];
    char *plustoken[60];
    int sum = 0;
    for (int i = 0; i < 60; i++)
        minustoken[i] = plustoken[i] = NULL;

    scanf("%s", array);
    /* 마이너스로 토크나이징 */
    char *ptr = strtok(array, "-");
    minustoken[0] = ptr;
    for (int i = 1; ptr != NULL; i++)
    {
        ptr = strtok(NULL, "-");
        minustoken[i] = ptr;
    }
    for (int i = 0; minustoken[i] != NULL; i++)
    {
        int tmp_sum = 0;
        /* 플러스 토큰 분할 */
        char *ptr = strtok(minustoken[i], "+");
        plustoken[0] = ptr;
        for (int j = 1; ptr != NULL; j++)
        {
            ptr = strtok(NULL, "+");
            plustoken[j] = ptr;
        }
        /* 부분합 tmp_sum 계산 */
        for (int j = 0; plustoken[j] != NULL; j++)
        {
            int data = atoi(plustoken[j]);
            tmp_sum += data;
        }

        /* i = 0일 경우에만 플러스 / 나머지는 마이너스 */
        if (i == 0)
            sum += tmp_sum;
        else
            sum -= tmp_sum;
    }
    printf("%d", sum);
}