#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int n = 0, m = 0;

vector<vector<string>> DP;

string add(string s1, string s2)
{
    vector<char> vec;

    int max_size = max(s1.size(), s2.size());
    int min_size = min(s1.size(), s2.size());

    // 이게 자릿수 때문에 불가능할수도 있음
    // long long l1 = stol(s1);
    // long long l2 = stol(s2);

    int additional = 0;
    for (int idx = 1; idx <= max_size; idx++)
    {
        if (idx <= min_size)
        {
            // 나머지 연산
            int last_l1 = (s1[s1.size() - idx]) - '0';
            int last_l2 = (s2[s2.size() - idx]) - '0';
            int tmp = last_l1 + last_l2 + additional;
            vec.push_back((tmp) % 10);
            additional = tmp / 10;
        }
        else
        {
            int last = 0;
            if (s1.size() > s2.size())
                last = (s1[s1.size() - idx]) - '0'; // '1' -> 1
            else
                last = (s2[s2.size() - idx]) - '0';
            int tmp = last + additional;
            vec.push_back((tmp) % 10);
            additional = tmp / 10;
        }
    }
    if (additional != 0)
        vec.push_back(additional);

    reverse(vec.begin(), vec.end());

    string answer = "";
    for (auto k : vec)
    {
        answer.push_back(k + '0');
    }
    return answer;
}

string func_C(int n, int m)
{
    if (m == 0 || n == m || n == 1)
    {
        return "1";
    }

    if ((DP[n][m]).compare("-1") != 0)
        return DP[n][m];

    else
    {
        DP[n][m] = add(func_C(n - 1, m - 1), func_C(n - 1, m));
        return DP[n][m];
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < 101; i++)
    {
        vector<string> vec;
        for (int j = 0; j < 101; j++)
        {
            vec.push_back("-1");
        }
        DP.push_back(vec);
    }
    string answer = func_C(n, m);

    cout << answer;
}