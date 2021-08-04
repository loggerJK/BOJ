/*  
https://www.acmicpc.net/problem/2252
2252 : 줄 세우기
위상 정렬 : topological sort
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define maxM 100000 // 10^5
#define maxN 32000

int N = 0, M = 0;

vector<int> adjList[maxN + 1];
int parent[maxN + 1] = {
	0,
};
int visit[maxN + 1] = {
	0,
};
vector<int> result;

void DFS(int start)
{

	// 방문 체크
	if (visit[start] == 1)
		return;

	// 인접 노드들을 DFS
	for (int i = 0; i < adjList[start].size(); i++)
	{
		DFS(adjList[start][i]);
	}

	// 종료할때 기록
	result.push_back(start);
	//방문처리
	visit[start] = 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// edge init
	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		// b -> a edge를 추가해준다
		adjList[b].push_back(a);
		parent[a] = b;
	}

	// incoming edge가 없는 노드들 (indegree == 0)인 노드들에 대해서 DFS를 수행해준다
	// 결국은 루트노드들이지 뭐
	for (int i = 1; i <= N; i++)
	{
		// 루트 노드들은 부모 노드가 없으므로 parent가 0이다
		if (parent[i] == 0)
			// 이러한 루트 노드들에 대해서 DFS를 수행해준다
			DFS(i);
	}

	// 역방향 바꾸기
	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++)
	{
		cout << (*iter) << " ";
	}
}