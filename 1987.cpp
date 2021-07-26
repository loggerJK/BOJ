/* 
#1987 알파벳
사용 알고리즘 : DFS

- 귀찮으니까 알파벳은 숫자로 변경해서 저장
ex)
A -> 0
B -> 1
...
Z -> 25


 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> node_visited;
vector<bool> alphabet_visited;
vector<vector<int>> map;
int R = 0, C = 0, MAX = 0;

/* 
return 0 : 탐색하지 않고 종료
return 1 : 탐색 완료 후 종료
 */
int traverse(int i, int j, int depth)
{
    // 범위 밖의 인덱스라면 종료
    if (i < 0 || i >= R || j < 0 || j >= C)
        return 0;

    /*  
    1. 이미 방문한 노드이거나
    2. 이미 방문한 알파벳이라면
    그대로 종료
    if 문 실행 X -> 모든 조건이 false임을 보장
    */
    if (node_visited[i][j] || alphabet_visited[map[i][j]])
        return 0;

    /* 방문처리 */
    node_visited[i][j] = true;
    alphabet_visited[map[i][j]] = true;

    int cnt = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int d = 0; d < 4; d++)
    {
        cnt += traverse(i + dx[d], j + dy[d], depth + 1);
    }

    /*  모든 인접 노드가 방문 불가능하다면 최대 max 값 업데이트*/
    if (cnt == 0)
        if (MAX < depth)
            MAX = depth;

    /* 방문처리 해제 */
    node_visited[i][j] = false;
    alphabet_visited[map[i][j]] = false;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // init & input

    cin >> R >> C;

    for (int i = 0; i < 30; i++)
        alphabet_visited.push_back(false);

    for (int x = 0; x < R; x++)
    {
        vector<int> row_map;
        vector<bool> row_node_visited;
        for (int y = 0; y < C; y++)
        {
            char input = 0;
            cin >> input;
            // int로 바꿔서 저장
            row_map.push_back((int)(input - 'A'));
            row_node_visited.push_back(false);
        }
        map.push_back(row_map);
        node_visited.push_back(row_node_visited);
    }

    traverse(0, 0, 1);

    cout << MAX;
}
