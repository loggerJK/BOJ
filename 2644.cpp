#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<bool> visits;
vector<int> dist;

int n, startnode, endnode, m;

void DFS(int node, int depth)
{
    if (visits[node] == true) return;
    visits[node] = true;
    dist[node] = depth;

    for (auto e : edge[node])
    {
        if(visits[e] == false)
            DFS(e, depth + 1);
    }

    return;

}
int main()
{
    cin >> n >> startnode >> endnode>> m;

    edge = vector<vector<int>> (101, vector<int> {});
    visits = vector<bool> (101, false);
    dist = vector<int> (101, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    DFS(startnode, 0);

    cout << dist[endnode];
}