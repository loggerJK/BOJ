// Floyd Warshall
#include <stdio.h>
#define INF 99999999
int n = 0, m = 0; //  각각 vertice와 edge의 개수를 의미한다.
// 1 ~ n 까지, n x n matrix를 다룬다.
int cost[101][101];
int path[101][101]; // path가 없다면 -1, 있다면 path의 cost를 저장한다.
int MIN(int a, int b)
{
    if (a > b)
        return b;
    else
    {
        return a;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    // init
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
        {
            cost[i][j] = INF;
        }
    // path 정보를 업데이트한다.
    for (int i = 0; i < m; i++)
    {
        int x = 0, y = 0, d = 0;
        scanf("%d %d %d", &x, &y, &d);
        if (d < cost[x][y])
            cost[x][y] = d;
    }

    // 플로이드 와샬 알고리즘 실행
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cost[i][j] = MIN(cost[i][j], cost[i][k] + cost[k][j]);
            }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                printf("%d ", (cost[i][j] == INF) ? 0 : cost[i][j]);
            else
                printf("0 ");
        }

        printf("\n");
    }
}