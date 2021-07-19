#include <stdio.h>

int main()
{
    long long N = 0;
    scanf("%lld", &N);

    N %= 8;
    if (N == 1)
        printf("1");
    else if (N == 2 || N == 0)
        printf("2");
    else if (N == 3 || N == 7)
        printf("3");
    else if (N == 4 || N == 6)
        printf("4");
    else if (N == 5)
        printf("5");
}