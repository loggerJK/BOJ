#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int V, E, K, from, to, w;
vector<pair<int, int>> v[20001];
priority_queue<pair<int, int>> pq;
bool visited[20001];
int dis[20001];
int INF = 1000000;

void dijkstra()
{
    dis[K] = 0;
    pq.push(make_pair(0, K));

    while (!pq.empty())
    {
        int current = pq.top().second;
        int value = -pq.top().first;
        pq.pop();
        if (visited[current] == false)
        {
            visited[current] = true;
            for (int i = 0; i < v[current].size(); i++)
            {
                // v - u
                //  u = v[current][i]
                if (dis[v[current][i].first] > dis[current] + v[current][i].second)
                {
                    dis[v[current][i].first] = dis[current] + v[current][i].second;
                    pq.push(make_pair(-dis[v[current][i].first], v[current][i].first));
                }
            }
        }
    }
}
int main(void)
{

    cin >> V;
    cin >> E;

    cin >> K; //출발점
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> w;
        v[from].push_back(make_pair(to, w));
        v[to].push_back(make_pair(from, w));
    }
    for (int i = 1; i <= V; i++)
    {
        dis[i] = INF;
    }
    dijkstra();
    cout << dis[238] << endl;
}
