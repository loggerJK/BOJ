/* https://www.acmicpc.net/problem/192 */
#include <iostream>
#include <algorithm>
#define maxSize 500500
int cnt = 0;

/* 인덱스를 반환하는 함수. 존재하지 않는다면 -1을 반환한다 */
int lowerBoundary(int key, int arr[], int beginIdx, int endIdx)
{
    int midIdx = (beginIdx + endIdx) / 2;

    if (endIdx <= beginIdx)
        if (arr[beginIdx] == key)
            return beginIdx;
        else
            return -1;

    if (key <= arr[midIdx])
        return lowerBoundary(key, arr, beginIdx, midIdx);
    else
        return lowerBoundary(key, arr, midIdx + 1, endIdx);
}
int upperBoundary(int key, int arr[], int beginIdx, int endIdx)
{
    int midIdx = 0;

    if ((beginIdx + endIdx) % 2 == 0)
        midIdx = (beginIdx + endIdx) / 2;
    else
        midIdx = (beginIdx + endIdx) / 2 + 1;

    if (endIdx <= beginIdx)
        if (arr[beginIdx] == key)
            return beginIdx;
        else
            return -1;

    if (arr[midIdx] <= key)
        return upperBoundary(key, arr, midIdx, endIdx);
    else
        return upperBoundary(key, arr, beginIdx, midIdx - 1);
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
    std::sort(inputData, inputData + N);
    scanf("%d", &M);

    /* M번에 걸쳐서 binarySearch를 수행한다 */
    for (int i = 0; i < M; i++)
    {
        int key = 0;
        scanf("%d", &key);
        int lower = lowerBoundary(key, inputData, 0, N - 1);
        int upper = upperBoundary(key, inputData, 0, N - 1);
        if (lower == -1 || upper == -1)
            printf("0 ");
        else
            printf("%d ", upper - lower + 1);
    }
    //   system("pause");
}