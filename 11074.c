#include <stdio.h>
#include <stdlib.h>

int M = 0, N = 0, K = 0;
int data[11];

void func(int a, int b)
{
    int quotient = a / data[b];
    int remainder = a % data[b];
    M += quotient;
    if (remainder > 0)
    {
        func(remainder, b - 1);
    }
    else
    {
        return;
    }
}

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        data[i] = -1;
    }

    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &data[i]);
    }
    func(K, N);
    printf("%d", M);
}