// Dijkstra
#include <stdio.h>
#include <vector>
#include <queue>
#define maxV 501
#define maxE 10001
#define white 0
#define gray 1
#define black 2
#define INF 999999999
#define pii pair<int, int>
using namespace std;

int V = 0, E = 0, S = 0, D = 0;
int d[maxV];     // save shortest path
int visit[maxV]; // check visit
struct compare
{
    bool operator()(int i, int j)
    {

        return d[i] > d[j]; // minheap을 만들도록 정의
    }
};
// 기본적으로 maxheap이므로 구조체를 다시 정의해주어야 한다.
priority_queue<int, vector<int>, compare> pq; // priority queue for Dijkstra
vector<pii> list[maxV];                       // Adjacency List
vector<int> pre[maxV];                        // predecessor를 저장하는 벡터 배열
queue<int> q;                                 // BFS를 위한 Queue

int MIN(int a, int b);
long long MIN(long long a, long long b);
void Dijkstra(int a);
void Delete_BFS(int a);

int main()
{
    while (1)
    {
        /* code */
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
            return 0;
        scanf("%d %d", &S, &D);
        // init vector
        for (int i = 0; i < maxV; i++)
        {
            d[i] = INF;
            visit[i] = white;
            list[i].clear();
            pre[i].clear();
        }

        // get input, make edge
        for (int i = 0; i < E; i++)
        {
            int x = 0, y = 0, d = 0;
            scanf("%d %d %d", &x, &y, &d);
            list[x].push_back(make_pair(y, d)); // directed graph
        }

        // Run Dijkstra for starting point S
        Dijkstra(S);

        // Delete edges included in shortest path
        // init visit array
        for (int i = 0; i < maxV; i++)
            visit[i] = white;
        Delete_BFS(D);

        // Run Dijkstra once more
        for (int i = 0; i < maxV; i++)
        {
            d[i] = INF;
            visit[i] = white;
            pre[i].clear();
            // printf("\n----------------------\n");
            // for (int j = 0; j < list[i].size(); j++)
            // {
            //     printf("%d",  )
            // }
        }
        Dijkstra(S);

        printf("%d\n", (d[D] >= INF) ? -1 : d[D]);
    }
}

void Dijkstra(int S) // S부터 모든 정점까지의 최단거리를 d[]에 저장한다
{
    d[S] = 0; // distance init
    visit[S] = white;
    pq.push(S);
    while (!pq.empty())
    {
        // pop
        int x = pq.top();
        pq.pop();
        if (visit[x] == black)
            continue; // 이미 최단거리가 완료된 vertice는 검사하지 않는다.
        // Update adjacent and Push
        for (int i = 0; i < list[x].size(); i++)
        {
            int y = list[x][i].first;
            int xtoy = list[x][i].second;

            // 모든 최단거리에 속하는 간선을 조사해야하기 때문에 대상 노드가 방문완료라도 간선을 검사한다.
            // if (visit[y] == black)
            //     continue;

            int updating_d = d[x] + xtoy;
            if (d[y] < updating_d)
            {
                // Do nothing
                continue;
            }
            else if (d[y] == updating_d)
            {
                // y의 predecessor 배열에 x를 추가한다
                pre[y].push_back(x);
            }
            else if (d[y] > updating_d)
            {
                // y의 최단거리를 업데이트 한다
                d[y] = updating_d;

                // y의 predecessor를 초기화한 후, x를 추가한다.
                pre[y].clear();
                pre[y].push_back(x);
            }
            // push destination
            pq.push(y);
        }
        visit[x] = black;
    }
}

void Delete_BFS(int a) // a부터 시작해서 차례대로 pre에 들어있는 간선을 삭제한다.
{
    visit[a] = gray;
    q.push(a);

    while (!q.empty())
    {
        // pop
        int y = q.front();
        q.pop();
        // pre[y]에 저장된 edge 삭제, x는 queue에 push
        for (int i = 0; i < pre[y].size(); i++)
        {

            int x = pre[y][i]; // x -> y edge를 삭제해야 함
            // printf("%d to %d\n", x, y);
            for (int k = 0; k < list[x].size(); k++)
            {
                if (y == list[x][k].first)
                {
                    // delete list[x][k]
                    list[x].erase(list[x].begin() + k);
                }
            }
            q.push(x);
        }
    }
}