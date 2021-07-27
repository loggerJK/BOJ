/* 
10026 : 적록색약
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/* 
R = 0
G = 1
B = 2
 */
vector<vector<int>> map1;
/* 
R,G = 0
B = 2
 */
vector<vector<int>> map2;
vector<vector<bool>> visit1;
vector<vector<bool>> visit2;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int N = 0;
int cnt_group_1 = 0;
int cnt_group_2 = 0;

void traverse1(int i, int j)
{
    // 시작점이 이미 grouping 되어 있다면, 개수를 세지 않고 종료한다
    if (visit1[i][j] == true)
        return;
    else
    {
        // 시작점 컬러 체크
        int init_color = 0;
        init_color = map1[i][j];
        q1.push(make_pair(i, j));
        while (!q1.empty())
        {
            /*  
            컬러가 같다면
            - 방문 체크
            - 인접 노드 큐에 푸쉬
            이미 방문한 노드이거나 컬러가 같지 않다면
            - 방문 x
            */
            int i = 0, j = 0;
            i = q1.front().first;
            j = q1.front().second;
            q1.pop();

            if (visit1[i][j] == true || init_color != map1[i][j])
                continue;

            // 방문하지 않은 노드이고 컬러가 같은 경우
            visit1[i][j] = true;
            int di[4] = {-1, 1, 0, 0};
            int dj[4] = {0, 0, -1, 1};
            for (int d = 0; d < 4; d++)
            {
                int new_i = i + di[d];
                int new_j = j + dj[d];
                if (new_i >= 0 && new_i < N && new_j >= 0 && new_j < N)
                    q1.push(make_pair(new_i, new_j));
            }
        }
    }
    cnt_group_1++;
}

void traverse2(int i, int j)
{
    // 시작점이 이미 grouping 되어 있다면, 개수를 세지 않고 종료한다
    if (visit2[i][j] == true)
        return;
    else
    {
        // 시작점 컬러 체크
        int init_color = 0;
        init_color = map2[i][j];
        q2.push(make_pair(i, j));
        while (!q2.empty())
        {
            /*  
            컬러가 같다면
            - 방문 체크
            - 인접 노드 큐에 푸쉬
            이미 방문한 노드이거나 컬러가 같지 않다면
            - 방문 x
            */
            int i = 0, j = 0;
            i = q2.front().first;
            j = q2.front().second;
            q2.pop();

            if (visit2[i][j] == true || init_color != map2[i][j])
                continue;

            // 방문하지 않은 노드이고 컬러가 같은 경우
            visit2[i][j] = true;
            int di[4] = {-1, 1, 0, 0};
            int dj[4] = {0, 0, -1, 1};
            for (int d = 0; d < 4; d++)
            {
                int new_i = i + di[d];
                int new_j = j + dj[d];
                if (new_i >= 0 && new_i < N && new_j >= 0 && new_j < N)
                    q2.push(make_pair(new_i, new_j));
            }
        }
    }
    cnt_group_2++;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        vector<int> row1;
        vector<int> row2;
        vector<bool> visit_row;
        for (int j = 0; j < N; j++)
        {
            visit_row.push_back(false);
            char input = 0;
            cin >> input;
            switch (input)
            {
            case 'R':
                row1.push_back(0);
                row2.push_back(0);
                break;
            case 'G':
                row1.push_back(1);
                row2.push_back(0);
                break;
            case 'B':
                row1.push_back(2);
                row2.push_back(2);
                break;
            }
        }
        map1.push_back(row1);
        map2.push_back(row2);
        visit1.push_back(visit_row);
        visit2.push_back(visit_row);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {

            // (i,j)를 포함하는 그룹을 탐색한다
            traverse1(i, j);
            traverse2(i, j);
        }
    cout << cnt_group_1 << " ";
    cout << cnt_group_2;
}