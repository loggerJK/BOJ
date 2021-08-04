
/* 
https://www.acmicpc.net/problem/5719
5719 : 거의 최단 경로
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define maxN 500
#define maxDist 2000000000
#define pii pair<int, int>
using namespace std;

int N = 0, M = 0, S = 0, D = 0, min_dist = 0, min_dist2 = -1;
bool visited[maxN + 10];	   // 각 노드의 방문 여부
int nodeList[maxN + 10];	   // 각 노드의 최단거리를 저장
vector<int> parent[maxN + 10]; // 벡터의 배열!!!
vector<vector<pii>> adjList;

typedef struct comp
{
	bool operator()(pii &a, pii &b)
	{
		return a.second > b.second;
	}
};

void dijkstra(int s)
{
	// (노드, 거리)쌍을 담을 minHeap 배열
	priority_queue<pii, vector<pii>, comp> pq;
	pq.push(make_pair(S, 0));
	while (!pq.empty())
	{
		pii cur = pq.top();
		pq.pop();
		// 방문 처리
		if (visited[cur.first] == true)
			continue;
		else
			visited[cur.first] = true;

		nodeList[cur.first] = cur.second;
		// 인접 노드에 대해 최단 거리 갱신
		// cur.first -> target
		for (int i = 0; i < adjList[cur.first].size(); i++)
		{
			int target = 0, edge_dist = 0;
			target = adjList[cur.first][i].first;
			edge_dist = adjList[cur.first][i].second;

			// 만약 같은 거리라면 부모 배열만 갱신
			if (nodeList[target] == cur.second + edge_dist)
			{
				parent[target].push_back(cur.first);
			}

			// 최단거리 갱신이 가능하다면
			if (nodeList[target] > cur.second + edge_dist)
			{
				int new_dist = cur.second + edge_dist;
				// 최단거리 갱신
				nodeList[target] = new_dist;
				// 부모 배열 최초 갱신
				parent[target].clear();
				parent[target].push_back(cur.first);
				// 우선순위 큐에 푸쉬
				pq.push(make_pair(target, new_dist));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		N = 0;
		M = 0;
		S = 0;
		D = 0;
		min_dist = 0;
		min_dist2 = -1;

		cin >> N >> M;
		// 종료조건
		if (N == 0 && M == 0)
			return 0;

		cin >> S >> D;

		// 전역 변수 초기화
		for (int i = 0; i < maxN + 10; i++)
		{
			visited[i] = false;
			nodeList[i] = maxDist;
			parent[i].clear();
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

		// 다익스트라를 돌린다
		dijkstra(S);
		min_dist = nodeList[D];

		// 끝노드부터 시작해 최단 경로에 해당하는 경로들을 제거한다
		// DFS
		int visited_BFS[maxN + 10] = {
			0,
		};
		queue<int> q;
		q.push(D);
		while (!q.empty())
		{
			int cur = 0;
			cur = q.front();
			q.pop();

			if (visited_BFS[cur] == 1)
				continue;
			else
				visited_BFS[cur] = 1;

			// ? -> cur 간선들을 모두 제거한다
			for (int i = 0; i < parent[cur].size(); i++)
			{
				int par = parent[cur][i];

				// par -> cur 간선을 제거한다
				vector<pii>::iterator iter;
				for (iter = adjList[par].begin(); iter != adjList[par].end();)
				{
					if ((*iter).first == cur)
					{
						adjList[par].erase(iter);
						break;
					}
					else
						iter++;
				}
				// par들을 큐에 푸시한다
				q.push(par);
			}
		}

		// 전역 변수 초기화
		for (int i = 0; i < maxN + 10; i++)
		{
			visited[i] = false;
			nodeList[i] = maxDist;
			parent[i].clear();
		}
		min_dist2 = -1;
		// 다익스트라
		dijkstra(S);

		min_dist2 = nodeList[D];
		if (min_dist2 == maxDist)
		// 거의 최단 경로가 없는 경우
		{
			min_dist2 = -1;
			cout << min_dist2 << "\n";
		}
		else if (min_dist < min_dist2)
			// 거의 최단 경로가 발견된 경우
			cout << min_dist2 << "\n";
	}

	// TC 하나 끝
}