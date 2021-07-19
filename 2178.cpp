#include <iostream>
#include <vector>
#include <queue>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define white 0
#define gray 1
#define black 2
using namespace std;

vii map, dist, visited;
queue<pii> q;
int N = 0, M = 0;
int near_arr[4][2];

void BFS(int a, int b)
{
  // initialize single source (a,b)
  dist[a][b] = 0;
  q.push(make_pair(a, b));
  while (!q.empty())
  {
    // 다음 방문할 노드를 선택한다
    pii target = q.front();
    q.pop();
    int a = 0, b = 0;
    a = target.first;
    b = target.second;
    int cur_dist = dist[a][b];
    // (a,b) 노드의 인접한 노드에 대해서 최단 경로를 갱신한다

    for (int i = 0; i < 4; i++)
    {
      // 새 좌표를 갱신한다
      int new_a = 0, new_b = 0;
      new_a = a + near_arr[i][0];
      new_b = b + near_arr[i][1];

      /* 
      방문 가능하다면
      1. 거리를 갱신한다
      2. 큐에 집어넣는다
      */
      if (0 <= new_a && new_a <= (N - 1) && 0 <= new_b && new_b <= (M - 1))
        if (map[new_a][new_b] == 1 && visited[new_a][new_b] == white)
        {
          visited[new_a][new_b] = gray;
          dist[new_a][new_b] = cur_dist + 1;
          q.push(make_pair(new_a, new_b));
        }
    }
    visited[a][b] = black;
  }
}

int main()
{
  // 변수 arr을 설정
  near_arr[0][0] = near_arr[1][1] = -1;
  near_arr[0][1] = near_arr[1][0] = near_arr[2][0] = near_arr[3][1] = 0;
  near_arr[2][1] = near_arr[3][0] = 1;

  // 1. N과 M을 입력받는다
  cin >> N >> M;

  // 2. 미로 정보를 입력받는다
  for (int i = 0; i < N; i++)
  {
    vector<int> vec;
    for (int j = 0; j < M; j++)
    {
      int data = 0;
      scanf("%1d", &data);
      vec.push_back(data);
    }
    map.push_back(vec);
  }

  // dist, visited 배열  초기화
  // 거리는 모두 -1 = inf로 초기화
  for (int i = 0; i < N; i++)
  {
    vector<int> vec;
    vector<int> vec2;
    for (int j = 0; j < M; j++)
    {
      vec.push_back(-1);
      vec2.push_back(white);
    }
    dist.push_back(vec);
    visited.push_back(vec2);
  }

  // 실제로는 (0,0) -> (N-1, M-1)
  // BFS를 돌리면서 최단거리를 체크한다

  BFS(0, 0);

  // // dist 배열을 출력해보자
  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j < M; j++)
  //   {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dist[N - 1][M - 1] + 1;
}