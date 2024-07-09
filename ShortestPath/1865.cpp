#include <iostream>
#include <vector>
#define pii pair<int, int>
#define INF 2000000000
using namespace std;

int TC = 0, N = 0, M = 0, W = 0;

vector<pii> edge[501];
int dist[501];

bool bellmanford()
{
    // 모든 간선에 대해 V-1 번의 Relaxation을 수행한다
    for (int n = 0; n < N - 1; n++)
    {
        for (int S = 1; S <= N; S++)
        {
            for (int i = 0; i < edge[S].size(); i++)
            {
                // S -> E 간선
                int cur_dist, E, T;
                cur_dist = dist[S];
                E = edge[S][i].first;
                T = edge[S][i].second;

                if (cur_dist + T < dist[E])
                {
                    dist[E] = cur_dist + T;
                }
            }
        }
    }
    // 만약 Relxation 가능한 간선이 있다면 (음수 사이클의 존재) True를 반환
    for (int S = 0; S < 501; S++)
    {
        for (int i = 0; i < edge[S].size(); i++)
        {
            // S -> E 간선
            int cur_dist, E, T;
            cur_dist = dist[S];
            E = edge[S][i].first;
            T = edge[S][i].second;

            if (cur_dist + T < dist[E])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        cin >> N >> M >> W;

        // 전역변수 초기화
        for (int i = 0; i < 501; i++)
        {
            edge[i].clear();
            dist[i] = INF;
        }

        // 도로
        for (int m = 0; m < M; m++)
        {
            int S = 0, E = 0, T = 0;
            cin >> S >> E >> T;
            // 양방향
            edge[S].push_back(make_pair(E, T));
            edge[E].push_back(make_pair(S, T));
        }

        // 웜홀
        for (int m = 0; m < W; m++)
        {
            int S = 0, E = 0, T = 0;
            cin >> S >> E >> T;
            // 방향성
            edge[S].push_back(make_pair(E, -T));
        }

        bool answer = bellmanford();

        if (answer)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}