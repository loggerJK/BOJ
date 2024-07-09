#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> dp(10001, -1);
vector<int> coins;


int findDp(int i)
{
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = 0;
    for (auto& coin : coins)
        dp[i] += findDp(i - coin);

    return dp[i];
}
int main()
{
    cin >> n >> k;
    coins = vector<int> (n, 0);

    int input = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        coins[i] = input;
    }

    dp[0] = 1;
    int answer = findDp(3);

    cout << answer;

}