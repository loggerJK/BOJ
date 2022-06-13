// Floyd Warhsall
/* 
왕복에 걸리는 시간 = d[i][X] + d[x][i]
for all i, '왕복시간'중 최댓값을 출력한다.
 */

#include <stdio.h>
#define INF 999999999
int N = 0, M = 0, X = 0;
int cost[1001][1001];
int MIN(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}
int main()
{
    // init, cost = INF는 해당 경로(혹은 최단경로)가 존재하지 않음을 의미한다.
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            cost[i][j] = INF;

    scanf("%d %d %d", &N, &M, &X);
    // 최초의 경로를 입력한다.
    for (int i = 0; i < M; i++)
    {
        int x = 0, y = 0, d = 0;
        scanf("%d %d %d", &x, &y, &d);
        if (d < cost[x][y])
            cost[x][y] = d;
    }

    // 플로이드 와샬 알고리즘 실행
    for (int k = 1; k <= N; k++) // 전체 cost에 대한 update를 vertice의 개수만큼 수행한다.
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                cost[i][j] = MIN(cost[i][j], cost[i][k] + cost[k][j]);
            }

    int maxVal = 0;
    for (int i = 1; i <= N; i++)
        if (i != X)
            maxVal = ((cost[i][X] + cost[X][i]) > maxVal) ? (cost[i][X] + cost[X][i]) : maxVal;

    printf("%d", maxVal);
}