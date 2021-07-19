#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

int main()
{
    using namespace std;
    int N = 0, M = 0, K = 0;
    scanf("%d %d", &N, &M);
    // declare N * M matrix
    // implements by vector of STL
    vector<vector<int>> matrix1(N);
    vector<vector<int>>::iterator v;
    for (v = matrix1.begin(); v != matrix1.end(); v++)
    {

        for (int j = 0; j < M; j++)
        {
            int value = 0;
            scanf("%d", &value);
            // printf("%d", value);
            v->push_back(value);
        }
    }
    // declare M * K matrix
    scanf("%d %d", &M, &K);
    vector<vector<int>> matrix2(M);
    for (v = matrix2.begin(); v != matrix2.end(); v++)
    {
        for (int j = 0; j < K; j++)
        {
            int value = 0;
            scanf("%d", &value);
            v->push_back(value);
        }
    }
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < M; j++)
    //         printf("A[%d][%d] = %d\n", i, j, matrix1[i][j]);
    // for (int i = 0; i < M; i++)
    //     for (int j = 0; j < K; j++)
    //         printf("B[%d][%d] = %d\n", i, j, matrix1[i][j]);
    // // declare N * K result matrix
    vector<vector<int>> result(N, vector<int>(K, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < M; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}