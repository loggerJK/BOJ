#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

long long N = 0, B = 0;
std::vector<std::vector<long long>> f(std::vector<std::vector<long long>> A, long long B);

int main()
{
    // given N, B in the first line
    // A is N * N matrix
    scanf("%lld %lld", &N, &B);

    // declare matrix A and set the values

    vector<vector<long long>> A(N);
    for (long long i = 0; i < N; i++)
        for (long long j = 0; j < N; j++)
        {
            long long value = 0;
            scanf("%lld", &value);
            value %= 1000;
            A[i].push_back(value);
        }

    A = f(A, B);

    for (vector<vector<long long>>::iterator v = A.begin(); v != A.end(); v++)
    {
        for (vector<long long>::iterator v2 = v->begin(); v2 != v->end(); v2++)
        {
            printf("%lld ", *v2);
        }
        printf("\n");
    }
}
vector<vector<long long>> cal(vector<vector<long long>> A, vector<vector<long long>> B)
{
    vector<vector<long long>> result(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result[i][j] += ((A[i][k] % 1000) * (B[k][j] % 1000)) % 1000;
                result[i][j] %= 1000;
            }
        }

    return result;
}

vector<vector<long long>> f(std::vector<std::vector<long long>> A, long long B)
{
    if (B <= 0)
    {
        // return I
    }
    if (B == 1)
        return A;
    // declare two matrix
    vector<vector<long long>> A1, A2;
    vector<vector<long long>> result(N, vector<long long>(N, 0));

    if (B % 2 == 0)
    {
        A1 = f(A, B / 2);
        result = cal(A1, A1);
        return result;
    }
    else
    {
        A1 = f(A, (B - 1) / 2);
        result = cal(A1, A1);
        result = cal(result, A);
        return result;
    }

    return result;
}