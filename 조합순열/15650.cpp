#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int N = 0, M = 0;
vector<int> num_vec;   // N
vector<int> candidate; // M
vector<int> tmp;

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        num_vec.push_back(i);
    }

    for (int i = 0; i < M; i++)
        tmp.push_back(0);
    for (int i = 0; i < (N - M); i++)
        tmp.push_back(1);
    assert(tmp.size() == N);

    do
    {
        candidate.clear();
        for (int i = 0; i < N; i++)
            if (tmp[i] == 0)
                candidate.push_back(num_vec[i]);
        // do
        // {
        for (int i = 0; i < M; i++)
            cout << candidate[i] << " ";
        // } while (next_permutation(candidate.begin(), candidate.end()));
        cout << '\n';

        // for (int i = 0; i < tmp.size(); i++)
        //     cout << tmp[i] << " ";

        // cout << '\n';

    } while (next_permutation(tmp.begin(), tmp.end()));
}