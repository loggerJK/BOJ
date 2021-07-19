// Greedy Algorithm

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>

using namespace std;

bool cmp(const pii &p1, const pii &p2);
int TC = 0;

int main()
{
    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        // input 입력받기
        int N = 0, a = 0, b = 0;
        vector<pii> vec; // (서류, 면접)
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> a >> b;
            vec.push_back(make_pair(a, b));
        }

        // vector를 서류점수 기준으로 sort
        sort(vec.begin(), vec.end(), cmp);

        int cnt = 0;
        int upperbound = N + 1;

        // N개의 지원자들을 검사하며 카운트를 올린다.
        for (int k = 0; k < N; k++)
        {
            if (vec[k].second < upperbound)
            {
                // 합격자에 추가한다.
                ++cnt;
                upperbound = vec[k].second;
            }
        }

        printf("%d\n", cnt);
    }
}

bool cmp(const pii &p1, const pii &p2)
{
    return p1.first < p2.first;
}