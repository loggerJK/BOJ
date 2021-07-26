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
        // 인접 노드들에 대해서 parent 배열을 업데이트하고 큐에 삽입한다
        // 사실 트리이므로 이미 방문한 노드들을 방문할 일이 없긴 함!
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            // 방문할 노드 번호 : j
            parent[j] = i;
            q.push(j);
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

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i];
    }
}