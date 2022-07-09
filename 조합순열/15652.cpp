#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

void backtracking(int i, int m, vector<int> v)
{
    v.push_back(i);
    if (m >= M)
    {
        for (int k = 0; k < v.size(); k++)
            cout << v[k] << " ";
        cout << '\n';
        return;
    }
    for (int j = i; j <= N; j++)
    {
        backtracking(j, m + 1, v);
    }
}

int main()
{
    cin >> N >> M;
    vector<int> v;
    for (int i = 1; i <= N; i++)
        backtracking(i, 1, v);
}