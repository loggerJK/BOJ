/* https://www.acmicpc.net/problem/1920 */
#include <iostream>
#include <algorithm>
#define maxSize 100001
bool greater_int(const int &a, const int &b)
{
    return a < b;
}
/* 인덱스를 반환하는 함수. 존재하지 않는다면 -1을 반환한다 */
int binarySearch(int key, int arr[], int beginIdx, int endIdx)
{
    if (endIdx < beginIdx)
    {
        /* 둘이 엇갈린다면 찾고 있는 수가 존재하지 않는 것이다 */
        return -1;
    }
    /* 중간 idx를 찾는다 */
    int midIdx = (beginIdx + endIdx) / 2;

    if (arr[midIdx] == key)
        return midIdx;
    else if (key < arr[midIdx])
        return binarySearch(key, arr, beginIdx, midIdx - 1);
    else if (arr[midIdx] < key)
        return binarySearch(key, arr, midIdx + 1, endIdx);
}
int main()
{
    int N = 0, M = 0;
    int inputData[maxSize];

    /* 
    N : 자연수의 개수
    M : searching을 수행할 자연수의 개수
     */

    /* 자연수 데이터를 입력한다 */
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &inputData[i]);

    /* binarySearch는 무조건 sorting을 해주어야 한다 */
    std::sort(inputData, inputData + N, greater_int);
    scanf("%d", &M);
    /* M번에 걸쳐서 binarySearch를 수행한다 */
    for (int i = 0; i < M; i++)
    {
        int key = 0;
        scanf("%d", &key);
        int result = binarySearch(key, inputData, 0, N - 1);
        if (result != -1) /* 만약 찾고 있는 수가 존재한다면 */
            printf("1\n");
        else
            printf("0\n");
    }
    system("pause");
}