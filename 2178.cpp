#include <iostream>
#include <vector>
#include <queue>
#define vii vector<vector<int>>
#define pii pair<int,int>
using namespace std;

vii map, dist;
queue<pii> q;
int N = 0, M = 0;
int near_arr [2][4];

void BFS(int a, int b) {
  // initialize single source (a,b)
  dist[a][b] = 0;
  q.push(make_pair(a,b));
  while (!q.empty()) {
    pii target = q.front();
    q.pop();
    int a = 0, b = 0;
    int cur_dist = dist[a][b];
    // 인접한 노드에 대해서 최단 경로를 갱신한다
    if ( )
  }

}


int main() {
  // 1. N과 M을 입력받는다
  cin >> N >> M;


  // 2. 미로 정보를 입력받는다
  for (int i = 0 ; i < N; i++) {
    vector<int> vec;
    for (int j = 0 ; j < M; j++) {
      int data = 0;
      scanf("%1d", &data);
      vec.push_back(data);
    }
    map.push_back(vec);
  }

  // dist 배열  초기화
  // 거리는 모두 -1 = inf로 초기화
  for (int i = 0; i < N; i++) {
    vector<int> vec;
    for (int j = 0; j < M; j ++) {
      vec.push_back(-1);
    }
    dist.push_back(vec);
  }

  // 잘 입력되었는지 확인
  for (int i = 0 ; i < N; i++) {
    for (int j = 0 ; j < M; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }

  // 실제로는 (0,0) -> (N-1, M-1)
  // BFS를 돌리면서 최단거리를 체크한다

  BFS(0,0);
  
}