#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll N = 0, M = 0, B = 0;
ll min_height = 999, max_height = -1;

vector<vector<ll>> map;
vector<pair<ll, ll>> save;

void bruteforce(ll h)
{
    vector<vector<ll>> map_ = map;
    ll B_ = B;
    bool able = true;
    ll time = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ll cur_height = map[i][j];
            if (h > cur_height)
            {
                // 블록을 이용해서 쌓는다 (2번 연산)
                B_ -= (h - cur_height);
                time += (h - cur_height);
            }
            else if (h < cur_height)
            {
                // 블록을 빼서 저장한다 (1번 연산)
                B_ += (cur_height - h);
                time += 2 * (cur_height - h);
            }
        }
    }

    if (B_ >= 0)
    {
        // (시간, 높이)를 저장한다
        save.push_back(make_pair(time, h));
    }
}

bool compare(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first != b.first)
    {
        // 오름차순
        return a.first < b.first;
    }
    else
    {
        // 내림차순
        return a.second > b.second;
    }
}

int main()
{
    cin >> N >> M >> B;

    for (ll i = 0; i < N; i++)
    {
        vector<ll> v;
        for (ll j = 0; j < M; j++)
        {
            ll input = 0;
            cin >> input;
            v.push_back(input);
            min_height = min(min_height, input);
            max_height = max(max_height, input);
        }
        map.push_back(v);
    }

    for (ll h = min_height; h <= max_height; h++)
    {
        bruteforce(h);
    }

    sort(save.begin(), save.end(), compare);

    cout << save[0].first << " " << save[0].second;
}