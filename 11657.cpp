// 벨만 포드 알고리즘
#include <iostream>
#include <vector>
#define INF 1e18
#define pii pair<long long,long long>

using namespace std;
long long N, M;
vector<vector<pii>> edge;
vector<long long> dist (501, INF);

int main()
{
    cin >> N >> M;

    edge = vector<vector<pii>>(501, vector<pii>{});

    for (long long i = 0; i < M; i++)
    {
        long long start, end, d;
        cin >> start >> end >> d;
        edge[start].push_back({end, d});
    }
    // 사이클 체크용 변수
    bool cycle = false;
    // 시작점 초기화
    dist[1]= 0;
    for (long long n = 0; n <= N; n++)
    {
        // Relxation
        for (long long i = 1; i < edge.size(); i++)
            for (long long j = 0; j < edge[i].size(); j++)
            {
                long long start, end, d;
                start = i;
                end = edge[i][j].first;
                d= edge[i][j].second;

                if ((dist[start]!= INF) && (dist[start] + d < dist[end]))
                {
                    dist[end] = dist[start] + d;
                    if (n == N) cycle = true;
                }
            }
    }
    if (cycle) cout << -1;
    else
    {
        for (long long i = 2; i <= N; i++)
            cout << ((dist[i] == INF) ? -1 : dist[i]) << endl;
    }


}