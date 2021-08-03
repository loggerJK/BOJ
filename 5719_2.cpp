
/* 
5719 : 거의 최단 경로
*/
#include <iostream>
#include <vector>
#include <queue>
#define maxN 500
#define pii pair<int, int>
using namespace std;

int N = 0, M = 0, S = 0, D = 0, min_dist = 0, min_dist2 = 0;
bool visited[maxN + 10]; // 각 노드의 방문 여부
int nodeList[maxN + 10]; // 각 노드의 최단거리를 저장
vector<vector<pii>> adjList;

int main()
{
    while (true)
    {
        cin >> N >> M;

        cin >> S >> D;

        // 종료조건
        if (N == 0 && M == 0)
            return 0;

        // 전역 변수 초기화
        for (int i = 0; i < maxN + 10; i++)
        {
            visited[i] = false;
            nodeList[i] = -1;
        }

        adjList.clear();
        for (int i = 0; i < N; i++)
        {
            vector<pii> row;
            adjList.push_back(row);
        }

        int u = 0, v = 0, p = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v >> p;
            adjList[u].push_back(make_pair(v, p));
        }

        dijkstra();
    }
}