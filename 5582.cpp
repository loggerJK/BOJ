#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout << s1 << s2;
    int N1 = 0, N2 = 0;
    N1 = s1.size();
    N2 = s2.size();
    vector<vector<int>> dp (N1, vector<int> (N2, 0));
    for (int i = 0; i < N1; i++)
        for (int j = 0; j < N2; j++)
        {
            if (s1[i] != s2[j])
                dp[i][j] = 0;
            else
            {
                if (i ==0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    int max_num = 0;
    for (int i = 0; i < N1; i++)
        for (int j = 0; j < N2; j++)
            max_num = max(max_num, dp[i][j]);
    cout << max_num;
}