#include <iostream>
#include <vector>

using namespace std;

int T = 0,
    N = 0;
vector<vector<int>> map;
vector<vector<int>> DP;

int dp_f(int i, int j)
{
    int other_i = 0;
    if (i == 0)
        other_i = 1;

    // 인덱스 조심!
    if (j < 0)
        return 0;

    // 이미 계산된 값이 있다면
    if (DP[i][j] != -1)
        return DP[i][j];
    else
    {
        DP[i][j] = max(dp_f(other_i, j - 1), dp_f(other_i, j - 2)) + map[i][j];
        return DP[i][j];
    }
}

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        N = 0;
        map.clear();
        DP.clear();

        cin >> N;
        for (int i = 0; i < 2; i++)
        {
            vector<int> v;
            map.push_back(v);
            DP.push_back(v);
        }

        for (int i = 0; i < N; i++)
        {
            int tmp = 0;
            cin >> tmp;
            map[0].push_back(tmp);
            DP[0].push_back(-1);
        }
        for (int i = 0; i < N; i++)
        {
            int tmp = 0;
            cin >> tmp;
            map[1].push_back(tmp);
            DP[1].push_back(-1);
        }

        int result = 0;
        result = max(dp_f(0, N - 1), dp_f(1, N - 1));
        cout << result << endl;
    }
}