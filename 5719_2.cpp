
/* 
https://www.acmicpc.net/problem/5719
5719 : 거의 최단 경로
*/
#include <iostream>
#include <vector>
#include <queue>
#define maxN 500
#define pii pair<int, int>
using namespace std;

int N = 0, M = 0, S = 0, D = 0, min_dist = 0, min_dist2 = -1;
bool visited[maxN + 10]; // 각 노드의 방문 여부
int nodeList[maxN + 10]; // 각 노드의 최단거리를 저장
int parent[maxN + 10]
vector<vector<pii>> adjList;

void dijkstra(int s)
{
	// (노드, 거리)쌍을 담을 minHeap 배열
	priority_queue<pii, vector<pii>, comp> pq;
	parentp[S] = -1;
	pq.push(make_pair(S,0));
	while(!pq.empty())
	{
		pii cur = pq.front();
		pq.pop();
		// 방문 처리
		if(visited[cur.front] == true)
			continue;
		else 
			visited[cur.front] = false;
		
		nodeList[cur.front] = cur.second;
		// 인접 노드에 대해 최단 거리 갱신
		for (int i = 0; i < adjList[cur.front].size(); i++)
		{
			int target = 0, edge_dist = 0;
			target = adjList[cur.front][i].front;
			edge_dist = adjList[cur.front][i].second;
			// 최단거리 갱신이 가능하다면
			if (nodeList[target] > cur.second + edge_dist)
			{
				int new_dist = cur.second + edge_dist;
				// 최단거리 갱신
				nodeList[target] = new_dist;
				// 부모 배열 갱신
				parent[target] = cur.front;
				// 우선순위 큐에 푸쉬
				pq.push(target,new_dist);
			}
		}
	}
}

int main()
{
    while (true)
    {
		N = 0; M = 0; S = 0; D = 0; min_dist = 0; min_dist2 = -1;

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
			parent[i] = -1;
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
		
		do{
			// 끝노드부터 시작해 최단 경로에 해당하는 경로들을 제거한다
			for (int i = D; i != -1;)
			{
				int cur_parent = 0;
				cur_parent = parent[i];
				
				// cur_parent -> i에 해당하는 edge를 제거한다.
				vector<pii>::iterator iter;
				for (iter = nodeList[cur_parent].begin(); iter!= nodeList[cur_parent].end(); iter++)
				{
					// 내가 찾던 노드라면
					if ( (*iter).first == i)
					{
						//삭제한다
						nodeList[cur_parent].erase(iter);
					}
				}
			}
			
			
			// 전역 변수 초기화
			for (int i = 0; i < maxN + 10; i++)
			{
				visited[i] = false;
				nodeList[i] = -1;
				parent[i] = -1;
			}
			min_dist2 = -1;
			// 다익스트라
			dijkstra(S);

			min_dist2 = nodeList[D];
			if (min_dist == min_dist2)
				// 이전과 동일한 최단 경로가 존재하는 경우
				continue;
			else if (min_dist < min_dist2)
				// 거의 최단 경로가 발견된 경우
				break;
			else if (min_dist2 == -1)
				// 거의 최단 경로가 없는 경우
				break;
    }
}