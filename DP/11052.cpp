#include <iostream>
#include <vector>

using namespace std;

vector<int> P;
vector<int> DP;
int N = 0;

int MAX(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int cal_DP(int n)
{
    if (n == 0)
        return DP[n] = 0;

    // 만약 초기값이 아니라면
    if (DP[n] != -1)
        return DP[n];

    else
    {
        int max_num = -1;
        for (int i = 0; i < n; i++)
            max_num = MAX(max_num, cal_DP(i) + P[n - i]);
        DP[n] = max_num;
        return DP[n];
    }
}

int main()
{
    cin >> N;

    P.push_back(0);
    DP.push_back(-1);
    for (int i = 1; i <= N; i++)
    {
        int input = 0;
        cin >> input;
        P.push_back(input);
        DP.push_back(-1);
    }

    cout << cal_DP(N);

    return 0;
}