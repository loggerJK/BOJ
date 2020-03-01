#include <stdio.h>
#include <stdlib.h>
int N = 0, K = 0;
int tab[1001];        /* 멀티탭에 꽂은 전기용품 정보 */
int tab_num[1001];    /* '멀티탭에 꽂은 전기용품'이 앞으로 얼마나 더 남아있는가 */
int order[1001];      /* 전기용품 삽입 순서 */
int ptr = 0, cnt = 0; // 다음에 꽂을 전기용품을 가리키고 있다.
int branch = 0;
int main()
{
    /* 전역변수 배열 초기화 */
    for (int i = 0; i < 1001; i++)
    {
        tab[i] = tab_num[i] = order[i] = 0;
    }
    scanf("%d %d", &N, &K);

    for (int i = 0; i < K; i++)
        scanf("%d", &order[i]);

    for (int i = 0; i < K; i++)
    {
        branch = 0; /* 변수 초기화 */

        /* order[ptr]이 꽂혀있는지 검사한다 */
        for (int i = 0; i < N; i++)
        {
            int tmp = tab[i];
            if (tmp == order[ptr])
            {
                /* 넣어야 하는 요소가 이미 멀티탭에 꽂혀있다면 for문을 탈출한다*/
                branch = 1;
                ptr++;
                break;
            }
            if (tmp == 0)
            { /*  */
                tab[i] = order[ptr];
                branch = 1;
                ptr++;
                break;
            }
        }
        if (branch == 0)
        { /* 멀티탭에 꽂혀있지 않다면 */
            /* 첫 순서가  가장 늦은 놈을 찾는다 */

            for (int i = 0; i < N; i++)
            {
                for (int j = ptr; j < K; j++)
                {
                    if (tab[i] == order[j])
                    {
                        tab_num[i] = j;
                        break;
                    }
                }
            }
            /* 가장 최소의 tab_num을 찾는다 */
            /* 나중에 다시 초기화 필요함 */
            int max = -1;
            int num = 0;
            for (int i = 0; i < N; i++)
            {
                if (tab_num[i] == 0)
                {
                    num = i;
                    break;
                }
                if (max < tab_num[i])
                {
                    max = tab_num[i];
                    num = i;
                }
            }

            /* 최대이거나 0인 num에 전기용품을 꽂는다 */
            tab[num] = order[ptr];
            ptr++;
            cnt++;
            /* tab_num 초기화 */
            for (int i = 0; i < N; i++)
            {
                tab_num[i] = 0;
            }
        }
    }
    printf("%d", cnt);
}