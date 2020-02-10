#include <stdio.h>

#define MAX 10000001
#define X 15746

int func(int N);
int dp[MAX];

int main()
{
    //dp 초기화
    for (int i = 0; i < MAX; i++)
    {
        dp[i] = -1;
    }
    int N = 0; // func[N]을 구하는게 목적
    scanf("%d", &N);

    int data = 0;
    for (int i = 1; i <= N; i++)
    {
        data = func(i);
    }

    printf("%d", data);

    // bottomUP 방식으로 func[N]을 계산
    /*
    
    for (int i = 1; i < 100; i++)
    {
        N = i;
        int data = 0;
        for (int i = 1; i <= N; i++)
        {
            data = func(i);
        }

        printf("%d\n", data);
    }
    */
}

int func(int N)
{
    // basecase를 먼저 설정한다
    if (N == 1)
        return 1;

    else if (N == 2)
        return 2;

    else if (dp[N] != -1)
        //p[N]값이 존재한다면
        return dp[N];

    else
    {
        dp[N] = (func(N - 1) + func(N - 2)) % X;
        return dp[N];
    }
}

//함수를 지나치게 많이 호출해서???