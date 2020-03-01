#include <iostream>
#include <algorithm>
#define size_ 100001
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    int N = 0; /* 묘목의 개수 */
    int data[size_];
    /* 배열 초기화 */
    for (int i = 0; i < size_; i++)
        data[i] = 0;

    /* TC 입력 */
    /* 1번부터 N번까지 입력을 받는다 */
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &data[i]);
    /* 1부터 N까지 내림차순으로 정렬한다 */
    std::sort(data + 1, data + N + 1, compare);

    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (max < data[i] + i)
            max = data[i] + i;
    }
    printf("%d", max + 1);
    // system("pause");
}
