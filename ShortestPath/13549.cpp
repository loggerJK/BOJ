#include <iostream>
#include <deque>
#include <vector>
#define pii pair<int, int>
#define maxnum 100000
#define maxdist 999999

using namespace std;

int N = 0, K = 0;

// (정점, 거리)
deque<pii> d;
// 최단거리 저장 배열
int dist[1000001];
bool visit_arr[1000001];

void zeroOneBFS(int N)
{
    // init
    dist[N] = 0;
    d.push_back(make_pair(N, 0));

    while (!d.empty())
    {
        int vertex = 0, cur_dist = 0;
        vertex = d.front().first;
        cur_dist = d.front().second;
        d.pop_front();

        // 방문검사
        if (visit_arr[vertex])
            continue;
        else
            visit_arr[vertex] = true;

        int add[2] = {-1, 1};
        for (int i = 0; i < 2; i++)
        {
            int next_vertex = 0;
            next_vertex = vertex + add[i];
            // check index
            if (next_vertex < 0 || next_vertex > maxnum)
                continue;
            // if relaxation is possible
            if ((cur_dist + 1) < dist[next_vertex])
            {
                dist[next_vertex] = cur_dist + 1;
                d.push_back(make_pair(next_vertex, dist[next_vertex]));
            }
        }
        int two_times = 0;
        two_times = 2 * vertex;
        if (two_times >= 0 || two_times <= maxnum)
        {
            if (cur_dist < dist[two_times])
            {
                dist[two_times] = cur_dist;
                d.push_front(make_pair(two_times, dist[two_times]));
            }
        }
    }
}

int main()
{
    cin >> N >> K;

    for (int i = 0; i <= maxnum; i++)
    {
        dist[i] = maxdist;
        visit_arr[i] = false;
    }

    int answer = 0;
    if (K <= N)
    {
        answer = N - K;
    }
    else
    {
        zeroOneBFS(N);
        answer = dist[K];
    }

    cout << answer;
}