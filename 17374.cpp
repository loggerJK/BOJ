#include <stdio.h>
#include <math.h>

long double MAX(long double a, long double b)
{
    if (a > b)
        return a;
    else
    {
        return b;
    }
}

long double MIN(long double a, long double b)
{
    if (a < b)
        return a;
    else
    {
        return b;
    }
}

int main()
{
    long double BIG = pow(10, 100);
    int iter = 0;
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++)
    {
        long double Pekaz[3] = {0, 0, 0}; // 비트, 코인, 베리
        int P = 0, Q = 0, A = 0, B = 0, C = 0, D = 0;
        scanf("%d %d %d %d %d %d", &P, &Q, &A, &B, &C, &D);
        // 모든 베리를 코인으로 바꾼다
        long double coin = D * MIN(Q / C, BIG / D);

        if (P <= coin)
        {
            long double N_max = MIN(P / A, BIG / B);
            long double n0 = -1;
            long double prev = -9999;
            for (long double i = 0; i <= N_max; i++)
            {
                long double data = MIN(P + A * i, coin - B * i);
                if (data >= prev)
                {
                    n0 = i;
                    prev = data;
                }
            }
            printf("%d\n", (int)MIN(P + A * n0, coin - B * n0));
        }
        else
        {
            // n0의 max값을 찾는다
            long double N_max = MIN(P / A, BIG / B);
            long double n0 = -1;
            long double prev = -9999;
            for (long double i = 0; i <= N_max; i++)
            {
                long double data = MIN(P - A * i, coin + B * i);
                if (data >= prev)
                {
                    n0 = i;
                    prev = data;
                }
            }
            printf("%d\n", (int)MIN(P - A * n0, coin + B * n0));
        }
    }
}