#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
#define pii pair<int, int>
#define tiiv tuple<int, int, vector<int>>
#define maxnum 100000
#define maxdist 999999

using namespace std;

int N = 0, K = 0;

// (정점, 거리, 경로)
deque<tiiv> d;
// 최단거리 저장 배열
int dist[1000001];
// vector<int> vec[1000001];
bool visit_arr[1000001];

pair<int, vector<int>> zeroOneBFS(int N, int K)
{
    // init
    dist[N] = 0;
    vector<int> v;
    v.push_back(N);
    d.push_back(make_tuple(N, 0, v));

    while (!d.empty())
    {
        int vertex = 0, cur_dist = 0;
        vector<int> cur_vec;
        vertex = get<0>(d.front());
        cur_dist = get<1>(d.front());
        cur_vec = get<2>(d.front());
        d.pop_front();

        // 방문검사
        if (visit_arr[vertex])
            continue;
        else
            visit_arr[vertex] = true;

        if (vertex == K)
            return make_pair(cur_dist, cur_vec);

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
                vector<int> next_vec = cur_vec;
                next_vec.push_back(next_vertex);
                // vec[next_vertex] = next_vec;

                dist[next_vertex] = cur_dist + 1;
                d.push_back(make_tuple(next_vertex, dist[next_vertex], next_vec));
            }
        }
        int two_times = 0;
        two_times = 2 * vertex;
        if (two_times >= 0 || two_times <= maxnum)
        {
            if ((cur_dist + 1) < dist[two_times])
            {
                vector<int> next_vec = cur_vec;
                next_vec.push_back(two_times);
                // vec[two_times] = next_vec;

                dist[two_times] = cur_dist + 1;
                d.push_back(make_tuple(two_times, dist[two_times], next_vec));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    for (int i = 0; i <= maxnum; i++)
    {
        dist[i] = maxdist;
        visit_arr[i] = false;
    }

    pair<int, vector<int>> answer = zeroOneBFS(N, K);

    cout << answer.first << '\n';
    for (int i = 0; i < answer.second.size(); i++)
        cout << answer.second[i] << " ";
}