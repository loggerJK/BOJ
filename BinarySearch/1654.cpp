#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <typeinfo>

using namespace std;

long long N = 0, K = 0;

vector<long long> k_vector;

bool binarySearch(long long mid_idx)
{
    long long sum = 0;
    // 10^4 연산
    for (auto num : k_vector)
    {
        sum += num / mid_idx;
    }
    if (sum >= N)
        return true;
    else
        return false;
}

int main()
{
    long long max_len = -1;
    cin >> K >> N;

    for (long long i = 0; i < K; i++)
    {
        long long input = 0;
        cin >> input;
        k_vector.push_back(input);
        max_len = max(max_len, input);
    }

    // 후보군 벡터 초기화

    double min_idx = 1,
           max_idx = max_len;
    long long mid_idx = 0;

    while (min_idx < max_idx)
    {
        // 정수 나누기
        mid_idx = ceil((min_idx + max_idx) / 2);

        if (binarySearch(mid_idx))
        {
            min_idx = mid_idx;
        }
        else
        {
            max_idx = mid_idx - 1;
        }
    }
    assert(min_idx == max_idx);
    double min_idx_ = min_idx;

    min_idx = 1;
    max_idx = max_len;

    long long answer = 0;

    while (min_idx <= max_idx)
    {
        // 정수 나누기
        long long mid_idx = ceil((min_idx + max_idx) / 2);

        if (binarySearch(mid_idx))
        {
            answer = max(answer, mid_idx);
            min_idx = mid_idx + 1;
        }
        else
        {
            max_idx = mid_idx - 1;
        }
    }

    assert(answer == min_idx_);
    cout << answer;
}