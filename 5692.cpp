#include <iostream>

int inputs = 0;

int factorial(int num)
{
    int result = 1;

    for (int i = 1; i <= num; i++)
    {
        result = result * i;
    }

    return result;
}

int main()
{
    while (1)
    {
        scanf("%d", &inputs);

        if (inputs == 0)
            return 0;

        // 자릿수 개수를 저장하는 변수
        int cnt = 0;

        //자릿수를 저장하는 변수
        int arr[5];

        //  0으로 초기화
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }

        // 자릿수를 저장
        for (int i = 0; i < 5; i++)
        {
            int tmp = 0;
            tmp = inputs % 10;
            arr[i] = tmp;
            inputs /= 10;
        }

        // 팩토리얼 계산
        int result = 0;
        for (int i = 0; i < 5; i++)
        {
            result += arr[i] * (factorial(i + 1));
        }

        printf("%d\n", result);
    }
}