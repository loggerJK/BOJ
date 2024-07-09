#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define tiii tuple<int, int, int, int>

using namespace std;

int N = 0, M = 0, K = 0;

vector<vector<int>> map;
int dist[1001][1001][11];
int visit_arr[1001][1001][11];
// i, j, 거리, depth
queue<tiii> q;

void BFS()
{
    dist[0][0][0] = 1;
    q.push(make_tuple(0, 0, 1, 0));

    while (!q.empty())
    {
        // pop
        int i, j, cur_dist, cur_depth;
        i = get<0>(q.front());
        j = get<1>(q.front());
        cur_dist = get<2>(q.front());
        cur_depth = get<3>(q.front()); // 0 <= cur_depth <= K
        q.pop();

        // 방문체크
        if (visit_arr[i][j][cur_depth])
            continue;
        else
            visit_arr[i][j][cur_depth] = true;

        int add_i[4] = {-1, 1, 0, 0};
        int add_j[4] = {0, 0, -1, 1};
        for (int l = 0; l < 4; l++)
        {
            int next_i, next_j;
            next_i = i + add_i[l];
            next_j = j + add_j[l];
            // 인덱스 체크
            if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M)
            {
                // 더 갈 수 있는 경우
                if (cur_depth < K)
                {
                    if ((cur_dist + 1) < dist[next_i][next_j][cur_depth])
                    {
                        dist[next_i][next_j][cur_depth] = cur_dist + 1;
                        // 다음 노드가 벽인 경우
                        if (map[next_i][next_j] == 1)
                            q.push(make_tuple(next_i, next_j, dist[next_i][next_j][cur_depth], cur_depth + 1));
                        // 다음 노드가 벽이 아닌 경우
                        else
                            q.push(make_tuple(next_i, next_j, dist[next_i][next_j][cur_depth], cur_depth));
                    }
                }
                // 벽을 부순 경우
                else
                {
                    // 벽이 아닌경우에만 최단거리 갱신 가능
                    if (map[next_i][next_j] != 1)
                        if ((cur_dist + 1) < dist[next_i][next_j][cur_depth])
                        {
                            dist[next_i][next_j][cur_depth] = cur_dist + 1;
                            q.push(make_tuple(next_i, next_j, dist[next_i][next_j][cur_depth], cur_depth));
                        }
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K;

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            for (int k = 0; k < 11; k++)
            {
                dist[i][j][k] = 99999999;
                visit_arr[i][j][k] = false;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (int j = 0; j < M; j++)
        {
            char ch;
            ch = cin.get();
            if (ch == '\n')
                ch = cin.get();
            v.push_back(ch - '0');
        }
        map.push_back(v);
    }

    BFS();

    int answer = 99999999;
    for (int k = 0; k <= K; k++)
        answer = min(answer, dist[N - 1][M - 1][k]);

    if (answer == 99999999)
        cout << -1;
    else
        cout << answer;
}