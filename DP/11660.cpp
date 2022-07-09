#include <iostream>
#include <vector>

using namespace std;

int N = 0,
    M = 0;

vector<vector<int>> vec;
vector<vector<int>> DP;

int dp(int x, int y)
{
    // 인덱스 체크
    if (x < 0 || x >= N || y < 0 || y >= N)
        return 0;

    if (DP[x][y] != -1)
        return DP[x][y];

    else
    {
        DP[x][y] = dp(x - 1, y) + dp(x, y - 1) - dp(x - 1, y - 1) + vec[x][y];
        return DP[x][y];
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 10^6
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        vector<int> v_;
        for (int j = 0; j < N; j++)
        {
            int input = 0;
            cin >> input;
            v.push_back(input);
            v_.push_back(-1);
        }
        vec.push_back(v);
        DP.push_back(v_);
    }

    // 10^6
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            dp(i, j);
    }

    for (int m = 0; m < M; m++)
    {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1;
        x2 -= 1;
        y1 -= 1;
        y2 -= 1;

        int result = 0;
        result = dp(x2, y2) - dp(x2, y1 - 1) - dp(x1 - 1, y2) + dp(x1 - 1, y1 - 1);
        // result = DP[x2][y2] - DP[x2][y1 - 1] - DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1];
        cout << result << '\n';
    }
}