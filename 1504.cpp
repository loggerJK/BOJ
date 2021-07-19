#include <stdio.h>
#include <vector>
#include <queue>
#define maxV 801
#define maxE 200001
#define white 0
#define black 1
#define INF 999999999
#define pii pair<int, int>
using namespace std;

int V = 0, E = 0, A = 0, B = 0;
int d[maxV];
int visit[maxV];
struct compare
{
    bool operator()(int i, int j)
    {

        return d[i] > d[j]; // minheap을 만들도록 정의
    }
};
// 기본적으로 maxheap이므로 구조체를 다시 정의해주어야 한다.
priority_queue<int, vector<int>, compare> pq; // priority queue for Dijkstra

vector<pii> list[maxV]; // Adjacency List
int MIN(int a, int b);
long long MIN(long long a, long long b);
void Dijkstra(int a);

int main()
{
    // var init
    for (int i = 0; i < maxV; i++)
    {
        visit[i] = white;
        d[i] = INF;
    }

    // get input
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++)
    {
        int x = 0, y = 0, d = 0;
        scanf("%d %d %d", &x, &y, &d);
        list[x].push_back(make_pair(y, d));
        list[y].push_back(make_pair(x, d));
    }

    scanf("%d %d", &A, &B);

    // Run Dijkstra 3 times
    long long d1A = 0, d1B = 0, dAB = 0, dA4 = 0, dB4 = 0;
    Dijkstra(1);
    d1A = d[A];
    d1B = d[B];
    for (int i = 0; i < maxV; i++)
    {
        visit[i] = white;
        d[i] = INF;
    }
    Dijkstra(A);
    dAB = d[B];
    dA4 = d[V];
    for (int i = 0; i < maxV; i++)
    {
        visit[i] = white;
        d[i] = INF;
    }
    Dijkstra(B);
    dB4 = d[V];
    long long result = MIN(d1A + dAB + dB4, d1B + dAB + dA4);

    printf("%lld", (result >= INF) ? -1 : result);
}

void Dijkstra(int a)
{
    d[a] = 0;
    // visit[a] = gray;
    pq.push(a);
    while (!pq.empty())
    {
        // pop
        int x = pq.top();
        pq.pop();
        // check visit
        if (visit[x] == black)
            continue;
        // Update shortest path of adjacent nodes for x
        for (int i = 0; i < list[x].size(); i++)
            if (visit[list[x][i].first] != black)
            {
                int dest = list[x][i].first;
                int dest_weight = list[x][i].second; // weight x -> dest
                // Updating shortest path
                d[dest] = MIN(d[dest], d[x] + dest_weight);
                // push priority queue
                pq.push(dest);
            }
        // mark visited
        visit[x] = black;
    }
}
int MIN(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
long long MIN(long long a, long long b)
{
    if (a > b)
        return b;
    else
        return a;
}