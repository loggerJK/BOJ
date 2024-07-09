#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define INF 9999999

using namespace std;
int N, M, K, X;

// 오름차순 정렬
struct compare
{
    bool operator()(pii a, pii b)
    {
        return a.second > b.second;
    }
};

vector<vector<int>> edge;
vector<int> dist;
vector<bool> visit;
// (노드, 거리)를 담는 배열
priority_queue<pii, vector<pii>, compare> pq;

void Dijkstra(int X)
{

    pq.push(make_pair(X, 0));
    dist[X] = 0;

    while (!pq.empty())
    {
        // pop
        pii tmp = pq.top();
        pq.pop();

        int node = 0, cur_dist = 0;
        node = tmp.first;
        cur_dist = tmp.second;

        // 방문 처리
        if (visit[node])
            continue;
        else
            visit[node] = true;

        vector<int>::iterator iter;
        for (iter = edge[node].begin(); iter != edge[node].end(); iter++)
        {
            int target = *iter;
            // 새로운 최단경로를 발견했다면
            if (cur_dist + 1 < dist[target])
            {
                // 거리 업데이트
                dist[target] = cur_dist + 1;
                // pq에 푸쉬
                pq.push(make_pair(target, cur_dist + 1));
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K >> X;
    // 초기화
    for (int i = 0; i <= N; i++)
    {
        vector<int> empty_vec;
        dist.push_back(INF);
        edge.push_back(empty_vec);
        visit.push_back(false);
    }

    for (int i = 0; i < M; i++)
    {
        int from = 0, to = 0;
        cin >> from >> to;
        edge[from].push_back(to);
    }

    Dijkstra(X);

    vector<int> distances;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == K)
            distances.push_back(i);
    }

    if (distances.empty())
        cout << -1;
    else
    {
        for (int i = 0; i < distances.size(); i++)
            cout << distances[i] << endl;
    }
}