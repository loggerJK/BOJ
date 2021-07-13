#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N = 0, M = 0;

typedef struct node
{
    int status;
    bool visited;
};

vector<vector<node>> map; // N X M 지도
vector<pair<pair<int, int>, bool>> zero_nodes_info;
vector<pair<int, int>> two_nodes_info;

void bfs(vector<vector<node>> &map, int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    // 인접 노드들 체크 , 조건 만족시 업데이트 및 큐에 푸쉬

    while (!q.empty())
    {
        int i = 0, j = 0;
        i = q.front().first;
        j = q.front().second;
        q.pop();

        // 방문 처리
        if (map[i][j].visited)
            continue;
        else
            map[i][j].visited = true;

        pair<int, int> arr[4];
        arr[0] = make_pair(i - 1, j);
        arr[1] = make_pair(i, j - 1);
        arr[2] = make_pair(i, j + 1);
        arr[3] = make_pair(i + 1, j);
        for (int iter = 0; iter < 4; iter++)
        {
            int i = 0, j = 0;
            i = arr[iter].first;
            j = arr[iter].second;
            if (i < 0 || j < 0 || i >= N || j >= M)
                // index out of range
                continue;
            // 바이러스가 감염 가능하다면
            if (map[i][j].status == 0 && map[i][j].visited == false)
            {
                map[i][j].status = 2;
                q.push(make_pair(i, j));
            }
        }
    }
}

int check_safezone()
{
    // 복사
    vector<vector<node>> new_map(map);
    // 모든 two_nodes_info를 시작점으로 해서 bfs를 돌린다
    for (int idx = 0; idx < two_nodes_info.size(); idx++)
    {
        int i = 0, j = 0;
        i = two_nodes_info[idx].first;
        j = two_nodes_info[idx].second;

        bfs(new_map, i, j);
        // cout << "--------------------------\n";
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << new_map[i][j].status;
        //     }
        //     cout << "\n";
        // }
    }
    // map을 순회하면서 0의 개수를 체크한다
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (new_map[i][j].status == 0)
                cnt++;
        }

    return cnt;
}

int MAX(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* 
사용법
zero_nodes_info[0] = ( (i,j), false )
(i,j)에 0번 노드가 있다
true : 벽으로 바뀐 상태이다
false : 벽으로 바뀌지 않은 상태이다
 */
int main()
{
    cin >> N >> M;

    // get Graph
    for (int i = 0; i < N; i++)
    {
        vector<node> row;
        map.push_back(row);
        for (int j = 0; j < M; j++)
        {
            int status = 0;
            cin >> status;
            //init and push node
            node new_node;
            new_node.status = status;
            new_node.visited = false;
            map[i].push_back(new_node);

            // 0인 칸의 좌표는 따로 보관한다
            if (status == 0)
            {
                zero_nodes_info.push_back(make_pair(make_pair(i, j), false));
            }
            if (status == 2)
            {
                two_nodes_info.push_back(make_pair(i, j));
            }
        }
    }

    // make three 0 nodes into 2
    vector<int> idx_vector;
    for (int i = 0; i < 3; i++)
        idx_vector.push_back(1);
    for (int i = 3; i < zero_nodes_info.size(); i++)
        idx_vector.push_back(0);

    sort(idx_vector.begin(), idx_vector.end());

    int num_safezone = 0;

    do
    {
        /* 
        1에 해당하는 0노드들을 1로 바꾸어준다 (빈칸 -> 벽)
         */
        for (int idx = 0; idx < idx_vector.size(); idx++)
        {
            if (idx_vector[idx] == 1)
            {
                // 좌표 정보
                int i = 0, j = 0;
                i = zero_nodes_info[idx].first.first;
                j = zero_nodes_info[idx].first.second;
                map[i][j].status = 1;
            }
        }
        // BFS를 돌리면서 안전구역의 수를 체크한다

        num_safezone = MAX(num_safezone, check_safezone());

        // 다시 원상태로 복구해준다
        for (int idx = 0; idx < idx_vector.size(); idx++)
        {
            if (idx_vector[idx] == 1)
            {
                // 좌표 정보
                int i = 0, j = 0;
                i = zero_nodes_info[idx].first.first;
                j = zero_nodes_info[idx].first.second;
                map[i][j].status = 0;
            }
        }
    } while (next_permutation(idx_vector.begin(), idx_vector.end()));

    cout << num_safezone;
}