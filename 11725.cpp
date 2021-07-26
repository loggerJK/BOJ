/*  
#11725 : 트리의 부모찾기
- 양방향 그래프로 구현
- Adjacency List
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> parent;
queue<int> q;
int N = 0;

void BFS(int idx)
{
    q.push(idx);
    while (!q.empty())
    {
        int i = 0;
        i = q.front();
        q.pop();

        if (visited[i] == true)
            continue;
        visited[i] = true;
        for (int j = 0; j < adj_list[i].size(); j++)
        {
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        vector<int> row;
        adj_list.push_back(row);
        visited.push_back(false);
        parent.push_back(-1);
    }

    for (int i = 0; i < N; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    BFS(1);
}