#include <iostream>
#include <vector>
using namespace std;

int n;
int treeData[100001];
bool visited[100001];
vector<int> tree[100001];

void dfs(int node)
{
    visited[node] = true;
    for (int i = 0; i < tree[node].size(); ++i)
    {
        int nextNode = tree[node][i];
        if (!visited[nextNode])
        {
            treeData[nextNode] = node;
            dfs(nextNode);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int nodeOne, nodeTwo;
        cin >> nodeOne >> nodeTwo;
        tree[nodeOne].push_back(nodeTwo);
        tree[nodeTwo].push_back(nodeOne);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i)
        cout << treeData[i] << endl;
}