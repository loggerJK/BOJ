/*
1520 : 내리막 길
DP 문제
*/

#include <iostream>
#include <vector>
#include <queue>
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;

/*
경로의 수를 저장하는 DP 배열
dp[i][j] = (i,j)까지의 경로의 수를 나타낸다
*/
ull dp[600][600] = {
	0,
};
int M = 0, N = 0;
vector<vector<ull>> map;
vector<vector<bool>> visited;
struct comp
{
	bool operator()(pii &a, pii &b)
	{
		return map[a.first][a.second] < map[b.first][b.second];
	}
};

/*
높이 내림차순 기준 우선순위 큐
*/
priority_queue<pii, vector<pii>, comp> pq;
int cnt = 0;
void traverse(int i, int j)
{
	pq.push(make_pair(i, j));
	while (!pq.empty())
	{
		// cnt++;
		int x = 0, y = 0;
		x = pq.top().first;
		y = pq.top().second;
		pq.pop();

		if (visited[x][y] == true)
			continue;
		visited[x][y] = true;

		// 	현재 높이를 저장
		ull cur_height = 0;
		cur_height = map[x][y];

		int dx[4] = {-1, 1, 0, 0};
		int dy[4] = {0, 0, 1, -1};

		for (int d = 0; d < 4; d++)
		{
			int next_x = 0, next_y = 0;
			next_x = x + dx[d];
			next_y = y + dy[d];

			// 인덱스를 벗어난 곳은 그냥 통과한다
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
				continue;

			// 내리막길이라면
			if (cur_height > map[next_x][next_y])
			{
				// 경로의 개수를 전파한다
				dp[next_x][next_y] += dp[x][y];
				// 우선순위 큐에 저장한다
				pq.push(make_pair(next_x, next_y));
			}
		}
		// cout << "cnt = " << cnt << "\n";
		// for (int i = 0; i < M; i++)
		// {
		// 	for (int j = 0; j < N; j++)
		// 		cout << dp[i][j] << " ";
		// 	cout << "\n";
		// }
		// cout << "\n=====================\n";
	}
}

int main()
{
	cin >> M >> N;

	// init map
	for (int i = 0; i < M; i++)
	{
		vector<ull> row;
		vector<bool> row_visited;
		for (int j = 0; j < N; j++)
		{
			ull input;
			cin >> input;
			row.push_back(input);
			row_visited.push_back(false);
		}
		map.push_back(row);
		visited.push_back(row_visited);
	}

	dp[0][0] = 1;
	traverse(0, 0);

	cout << dp[M - 1][N - 1];
}