#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> cleaned;
int cnt_clean = 0;

/* 로봇의 state 정의 */
/*  
(x,y,d)
현재 위치 = (i,j)
바라보는 방향 = d

- 벽이라면 무조건 청소되어있는 상태
*/
typedef struct Robot
{
    int x;
    int y;
    int d;
};
Robot robot;

bool somewhereLeft()
{
    int x = robot.x;
    int y = robot.y;

    // 하나라도 False가 있는 경우
    if (!cleaned[x - 1][y] || !cleaned[x][y + 1] || !cleaned[x + 1][y] || !cleaned[x][y - 1])
        return true;

    else
        return false;
}
bool isPossibleBackward()
{
    int next_x = robot.x, next_y = robot.y;
    if (robot.d == 0)
        next_x += 1;
    else if (robot.d == 1)
        next_y -= 1;
    else if (robot.d == 2)
        next_x -= 1;
    else if (robot.d == 3)
        next_y += 1;
    if (map[next_x][next_y] == 0)
        return true;
    else
        return false;
}
bool isPossibleLeft()
{
    int next_x = robot.x, next_y = robot.y;
    switch (robot.d)
    {
    case 0:
        next_y -= 1;
        break;
    case 1:
        next_x -= 1;
        break;
    case 2:
        next_y += 1;
        break;
    case 3:
        next_x += 1;
        break;
    }
    // 청소되어 있지 않으면
    if (cleaned[next_x][next_y] == false)
        return true;
    else
        return false;
}
void oneStepForward()
{
    switch (robot.d)
    {
    case 0:
        robot.x -= 1;
        break;
    case 1:
        robot.y += 1;
        break;
    case 2:
        robot.x += 1;
        break;
    case 3:
        robot.y -= 1;
        break;
    }
}
void oneStepBackward()
{
    switch (robot.d)
    {
    case 0:
        robot.x += 1;
        break;
    case 1:
        robot.y -= 1;
        break;
    case 2:
        robot.x -= 1;
        break;
    case 3:
        robot.y += 1;
        break;
    }
}

void rotateLeft()
{
    if (robot.d == 0)
        robot.d = 3;
    else if (robot.d == 1)
        robot.d = 0;
    else if (robot.d == 2)
        robot.d = 1;
    else if (robot.d == 3)
        robot.d = 2;
}

void makeClean()
{
    cleaned[robot.x][robot.y] = true;
    cnt_clean++;
    return;
}

void traverse()
{
    while (true)
    {
        makeClean();
        while (true)
        {
            if (somewhereLeft())
            {
                if (isPossibleLeft())
                {
                    rotateLeft();
                    oneStepForward();
                    break;
                }
                else
                {
                    rotateLeft();
                    continue;
                }
            }
            else
            {
                if (isPossibleBackward())
                {
                    oneStepBackward();
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // init
    int N = 0, M = 0;

    cin >> N >> M;
    cin >> robot.x >> robot.y >> robot.d;
    robot.x++;
    robot.y++;

    vector<int> row;
    vector<bool> cleaned_row;
    for (int j = 0; j < (M + 2); j++)
    {
        row.push_back(1);
        cleaned_row.push_back(true);
    }
    map.push_back(row);
    cleaned.push_back(cleaned_row);

    for (int i = 0; i < N; i++)
    {
        vector<int> row_;
        vector<bool> cleaned_row_;

        row_.push_back(1);
        cleaned_row_.push_back(true);
        for (int j = 0; j < M; j++)
        {
            int input = 0;
            cin >> input;
            row_.push_back(input);
            if (input == 0)
                cleaned_row_.push_back(false);
            else
                cleaned_row_.push_back(true);
        }
        row_.push_back(1);
        cleaned_row_.push_back(true);

        map.push_back(row_);
        cleaned.push_back(cleaned_row_);
    }

    map.push_back(row);
    cleaned.push_back(cleaned_row);

    traverse();

    cout << cnt_clean;
}