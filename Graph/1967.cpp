#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

vector<pii> edge[10001];
int dist[10001];
int visited[10001];

// return (제일 먼 정점, 거리)
void DFS(int cur_s, int distance)
{
    dist[cur_s] = distance;

    if (!visited[cur_s])
    {
        visited[cur_s] = true;

        for (int i = 0; i < edge[cur_s].size(); i++)
        {
            int next_s = 0, weight = 0;
            next_s = edge[cur_s][i].first;
            weight = edge[cur_s][i].second;
            if (!visited[next_s])
                DFS(next_s, distance + weight);
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < 10001; i++)
    {
        dist[i] = 0;
        visited[i] = false;
    }
    DFS(1, 0);
    int max_vertex = -1, max_dist = -1;
    for (int i = 1; i <= n; i++)
        if (max_dist < dist[i])
        {
            max_dist = dist[i];
            max_vertex = i;
        }

    for (int i = 0; i < 10001; i++)
    {
        dist[i] = 0;
        visited[i] = false;
    }
    DFS(max_vertex, 0);

    max_vertex = -1, max_dist = -1;
    for (int i = 1; i <= n; i++)
        if (max_dist < dist[i])
        {
            max_dist = dist[i];
            max_vertex = i;
        }

    cout << max_dist;
}