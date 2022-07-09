#include <iostream>
#include <deque>
#include <vector>
#include <tuple>
#include <algorithm>
#define pii pair<int, int>
#define tiiv tuple<int, int, vector<int>>
#define maxnum 100000
#define maxdist 999999

using namespace std;

int N = 0, K = 0;

// (정점, 거리, 경로)
deque<pii> d;
// 최단거리 저장 배열
int dist[1000001];
// vector<int> vec[1000001];
int parent[1000001];
bool visit_arr[1000001];

void zeroOneBFS(int N, int K)
{
    // init
    dist[N] = 0;
    vector<int> v;
    v.push_back(N);
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

        int add[3] = {-1, 1, vertex};
        for (int i = 0; i < 3; i++)
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
                parent[next_vertex] = vertex;
                d.push_back(make_pair(next_vertex, dist[next_vertex]));
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
        parent[i] = -1;
    }

    zeroOneBFS(N, K);

    cout << dist[K] << "\n";
    vector<int> path;
    int leaf_node = K;
    while (true)
    {
        path.push_back(leaf_node);
        // cout << leaf_node << " ";
        int parent_node = 0;
        parent_node = parent[leaf_node];
        if (parent_node == -1)
            break;
        else
        {
            leaf_node = parent_node;
        }
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}