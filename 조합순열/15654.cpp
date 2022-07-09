#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int N = 0, M = 0;
vector<int> vec;
vector<int> v_;
vector<int> tmp;

bool compare_(const int &a, const int &b)
{
    int a_idx = lower_bound(v_.begin(), v_.end(), a) - v_.begin();
    int b_idx = lower_bound(v_.begin(), v_.end(), b) - v_.begin();

    if (tmp[a_idx] < tmp[b_idx])
        return true;
    else
        return false;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int input = 0;
        cin >> input;
        vec.push_back(input);
    }

    // 오름차순 정렬
    sort(vec.begin(), vec.end());

    for (int i = 1; i <= M; i++)
        tmp.push_back(i);
    for (int i = 0; i < (N - M); i++)
        tmp.push_back(M + 1);

    do
    {
        v_ = vec;
        sort(v_.begin(), v_.end(), compare_);
        for (int i = 0; i < M; i++)
        {
            cout << v_[i] << "";
        }
        cout << '\n';

    } while (next_permutation(tmp.begin(), tmp.end()));
}
