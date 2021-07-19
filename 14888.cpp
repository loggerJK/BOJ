#include <iostream>
#include <string>
#include <algorithm>
#define num_size 12
#define bignum 1000000000
int data[num_size];
int N = 0; /* 수의 개수 */
/* 플러스 마이너스 곱 나눗셈 개수 저장 */
int oper[4];
int max = -bignum;
int min = bignum;

void f(int prev_data, int oper_, int ptr, int oper_arr[])
{
    /* 남아있는 연산자 수가 없다면 종료한다 */

    /* 만약 다음에 더할 수가 없다면 max 값과 min 값을 갱신하고 종료한다 */
    if (ptr >= N)
    {
        if (max < prev_data)
            max = prev_data;
        if (min > prev_data)
            min = prev_data;
        return;
    }
    if (oper_arr[oper_] <= 0)
        return;
    /* 
    0 플러스
    1 마이너스
    2 곱셈
    3 나눗셈
     */
    if (oper_ == 0)
    {
        int new_data = prev_data + data[ptr];
        int new_oper_data[4];
        std::copy(oper_arr, oper_arr + 4, new_oper_data);
        new_oper_data[0]--;
        for (int i = 0; i < 4; i++)
            f(new_data, i, ptr + 1, new_oper_data);
    }
    else if (oper_ == 1)
    {
        int new_data = prev_data - data[ptr];
        int new_oper_data[4];
        std::copy(oper_arr, oper_arr + 4, new_oper_data);
        new_oper_data[1]--;

        for (int i = 0; i < 4; i++)
            f(new_data, i, ptr + 1, new_oper_data);
    }
    else if (oper_ == 2)
    {
        int new_data = prev_data * data[ptr];
        int new_oper_data[4];
        std::copy(oper_arr, oper_arr + 4, new_oper_data);
        new_oper_data[2]--;
        for (int i = 0; i < 4; i++)
            f(new_data, i, ptr + 1, new_oper_data);
    }
    else if (oper_ == 3)
    {
        int new_data = prev_data / data[ptr];
        int new_oper_data[4];
        std::copy(oper_arr, oper_arr + 4, new_oper_data);
        new_oper_data[3]--;
        for (int i = 0; i < 4; i++)
            f(new_data, i, ptr + 1, new_oper_data);
    }
}

int main()
{
    for (int i = 0; i < num_size; i++)
        data[i] = 0;
    scanf("%d", &N);
    /* 0부터 N-1까지 숫자 입력 */
    for (int i = 0; i < N; i++)
        scanf("%d", &data[i]);
    for (int i = 0; i < 4; i++)
        scanf("%d", &oper[i]);

    for (int i = 0; i < 4; i++)
        f(data[0], i, 1, oper);

    printf("%d\n%d", max, min);
    // system("pause");
}