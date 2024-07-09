#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

int N, D, start, end;
vector<vector<pii>> edge;
vector<bool> visit;
vector<int> dist;

// Minheap이므로 오름차순 정렬
struct cmp{
    bool operator()(pii b, pii a)
    {
        return a.second < b.second;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;

void dijkstra()
{
    while(!pq.empty())
    {
        int node, d;
        node = pq.top().first;
        d = pq.top().second;
        pq.pop();

        // 방문 처리
        if (visit[node] == true) continue;
        // if (d > dist[node]) continue;
        visit[node] = true;
        dist[node] = d;

        // 인접 노드 푸시
        for (int i = 0; i < edge[node].size(); i++)
        {
            int j, dij;
            j = edge[node][i].first;
            dij = edge[node][i].second;
            if ((d + dij) < dist[j])
            {
                // dist[j] = d + dij;
                pq.push({j, (d+dij)});
            }
        }
    }
}

int main()
{
    cin >> N >> D;

    edge = vector<vector<pii>>(1000001, vector<pii>{});
    visit = vector<bool> (1000001, false);
    dist = vector<int>(1000001, 1000002);

    // 엣지 입력
    int start, end, d;
    for (int i = 0; i < D; i++)
        edge[i].push_back({i+1, 1});

    for (int i = 0; i < N; i++) 
    {
        cin >> start >> end >> d;
        edge[start].push_back({end, d});
    }

    // 다익스트라
    pq.push({0,0});
    dijkstra();

    cout << dist[D];

}