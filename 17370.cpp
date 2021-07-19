#include <stdio.h>
#define White 0
#define Black 1

int arr[1024][1024];
int N = 0;
int answerCount = 0;
void f(int x, int y, int arrow, int cnt) // 현재 위치, 이동해온 경로, 회전 횟수
{
    if (cnt == N) // N번 회전하였고
    {
        if (arr[x][y] == Black) // 사이클을 형성하는 경우
        {
            answerCount++;
        }
        return;
    }
    if (arr[x][y] == Black)
    {
        // N번 회전하지 않았음에도 Black인 경우
        return;
    }
    else if (arr[x][y] == White)
    {
        //방문처리
        arr[x][y] = Black;
        // 이전 arrow에 따라서 방문할 위치를 결정
        // DFS
        if (arrow == 0)
        {
            f(x + 3, y + 4, 1, cnt + 1);
            f(x - 3, y + 4, 5, cnt + 1);
        }
        else if (arrow == 1)
        {
            f(x, y + 5, 0, cnt + 1);
            f(x + 3, y - 4, 2, cnt + 1);
        }
        else if (arrow == 2)
        {
            f(x + 3, y + 4, 1, cnt + 1);
            f(x, y - 5, 3, cnt + 1);
        }
        else if (arrow == 3)
        {
            f(x + 3, y - 4, 2, cnt + 1);
            f(x - 3, y - 4, 4, cnt + 1);
        }
        else if (arrow == 4)
        {
            f(x, y - 5, 3, cnt + 1);
            f(x - 3, y + 4, 5, cnt + 1);
        }
        else if (arrow == 5)
        {
            f(x, y + 5, 0, cnt + 1);
            f(x - 3, y - 4, 4, cnt + 1);
        }
        arr[x][y] = White;
        return;
    }
}

int main()
{
    //init
    for (int i = 0; i < 1024; i++)
        for (int j = 0; j < 1024; j++)
            arr[i][j] = White;

    scanf("%d", &N);
    arr[512][512] = Black;
    f(512, 517, 0, 0);
    printf("%d", answerCount);
}