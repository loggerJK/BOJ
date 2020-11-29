#include <stdio.h>
#include <queue>
#define MaxNum 20001
#define INF 9999999
#define white 0
#define gray 1
#define black 2
#define pii pair<int, int>
using namespace std;
int d[MaxNum];
// int P[MaxNum][MaxNum];
vector<pair<int, int>> P[MaxNum];
char visit[MaxNum];
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
priority_queue<pii, vector<pii>, cmp> pq;
int V = 0, E = 0, s = 0;
void Dijkstra(int s);
int MIN(int a, int b);

int main()
{
    // init
    for (int i = 0; i < MaxNum; i++)
    {
        d[i] = INF;
        visit[i] = white;
        // for (int j = 0; j < MaxNum; j++)
        //     P[i][j] = INF;
    }

    scanf("%d %d", &V, &E);
    scanf("%d", &s);

    // edge의 값들을 입력한다
    for (int e = 0; e < E; e++)
    {
        int x = 0, y = 0, d = 0;
        scanf("%d %d %d", &x, &y, &d);
        P[x].push_back(pair<int, int>(y, d));
        // P[y].push_back(pair<int, int>(x, d));
    }
    Dijkstra(s);

    // 결과 출력

    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INF)
            printf("%s ", "INF");
        else
            printf("%d", d[i]);
        printf("\n");
    }
}

int MIN(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
void Dijkstra(int s)
{
    // s = starting vertex
    visit[s] = gray;
    d[s] = 0;
    pq.push(make_pair(s, 0));
    while (!pq.empty())
    {
        // pop
        int x = pq.top().first;
        int value = pq.top().second;
        pq.pop();
        // 이미 방문한 노드는 건너뛴다
        if (visit[x] == black)
            continue;
        // process : 인접노드들의 최단 경로를 업데이트한다.
        for (int y = 0; y < P[x].size(); y++)
        {
            int dest = P[x][y].first;
            if (visit[dest] != black)
            {
                d[dest] = MIN(d[dest], d[x] + P[x][y].second);
                // 경로가 업데이트된 노드들은 큐에 넣어준다.
                // printf("Updating Dest : %d\n", dest);
                pq.push(make_pair(dest, d[dest]));
                visit[dest] = gray;
            }
        }
        // 방문 처리
        visit[x] = black;
    }
}
