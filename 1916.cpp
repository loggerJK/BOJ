#include <stdio.h>
#include <vector>
#include <queue>
#define maxV 1001
#define maxE 100001
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
    }

    scanf("%d %d", &A, &B);

    // Run Dijkstra
    Dijkstra(A);

    printf("%d", d[B]);
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