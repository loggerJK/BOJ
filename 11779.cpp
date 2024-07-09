#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define pii pair<int,int>
using namespace std;

vector<bool> visits;
vector<int> dist;
vector<vector<pii>> edge;
vector<int> prevs;

// MinHeap이므로 오름차순 정렬
struct comp{
    bool operator()(pii b, pii a)
    {
        return a.second < b.second;
    }
};
priority_queue<pii, vector<pii>, comp> pq;
int n, m;

void dijkstra()
{
    while(!pq.empty())
    {
        int node, d;
        node = pq.top().first;
        d = pq.top().second;
        pq.pop();

        if(visits[node] == true) continue;
        visits[node] = true;

        for (auto& e:edge[node])
        {
            int next, nextd;
            next = e.first;
            nextd = e.second;
            if (dist[node] + nextd < dist[next])
            {
                // Relxation
                dist[next] = dist[node] + nextd;
                prevs[next] = node;
                pq.push({next, dist[next]});
            }
        }


    }
}

int main()
{
    cin >> n >> m;

    // 초기화
    visits = vector<bool> (1001, false);
    dist = vector<int>(1001, INF);
    prevs = vector<int>(1001, -1);
    edge = vector<vector<pii>> (1001, vector<pii> {});
    

    int start, end, d;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end >> d;
        edge[start].push_back({end, d});
    }

    cin >> start >> end;

    pq.push({start, 0});
    dist[start] = 0;
    dijkstra();

    cout << dist[end] << endl;

    int cnt = 0;
    vector<int> answer;
    while (end != start)
    {
        answer.push_back(end);
        end = prevs[end];
        cnt++;
    }
    cnt++;
    answer.push_back(end);

    cout << cnt << endl;
    for (auto iter = answer.rbegin(); iter!= answer.rend(); iter++)
        cout << *iter << " ";

}
