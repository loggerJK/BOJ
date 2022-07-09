#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int TC = 0;

bool compare(pii a, pii b)
{
    if (a.second > b.second)
        return true;
    else 
        return false;
}

int main()
{
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        // vector of (번호, 중요도)
        vector<pii> input_vec;
        vector<int> final_vec;
        int N = 0, M = 0;

        cin >> N >> M;

        // input_vec 초기화
        for (int i = 0; i < N; i++)
        {
            int importance = 0;
            cin >> importance;
            input_vec.push_back(make_pair(i, importance));
        }

        // 중요도 순으로 정렬한다
        vector<pii> sorted_vec = input_vec;
        sort(sorted_vec.begin(), sorted_vec.end(), compare);

        queue<pii> input_q;
        queue<pii> sorted_q;

        for (int i = 0; i < input_vec.size(); i++)
        {
            input_q.push(input_vec[i]);
            sorted_q.push(sorted_vec[i]);
        }

        while (!input_q.empty())
        {
            if (input_q.front().second == sorted_q.front().second)
            {
                // 둘 다 pop, 번호를 final에 저장
                final_vec.push_back(input_q.front().first);
                input_q.pop();
                sorted_q.pop();
            }
            else
            {
                input_q.push(input_q.front());
                input_q.pop();
            }
        }

        for (int i = 0; i < final_vec.size(); i++)
        {
            if (final_vec[i] == M)
                cout << i + 1 << endl;
        }
    }
}