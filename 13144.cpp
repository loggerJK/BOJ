#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

long long N;
vector<long long> nums;

int main ()
{
    cin >> N;
    long long n;
    for (long long i = 0; i < N; i++)
    {
        cin >> n;
        nums.push_back(n);
    }

    long long left = 0, right = 0;
    vector<bool> visit (100001, false);
    vector<long long> dp (N, -1);
    long long max_len = 0;
    for (right = 0; right < N;)
    {
        // 중복 발생
        if (visit[nums[right]] == true)
        {
            // 현재까지의 벡터를 저장한다
            // maxlens.push_back(q.size());
            // 중복이 없어질때까지 left를 옮기면서 visit 해제
            while(nums[left] != nums[right])
            {
                visit[nums[left]] = false;
                left++;
                // q.pop_front();
            }
            visit[nums[left]] = false;
            assert(nums[left] == nums[right] && "Assertion Error");
            left++;
            // q.pop_front();
        }
        else
        {
            visit[nums[right]] = true;
            // q.push_back(nums[right]);
            dp[right] = right - left + 1;
            right++;
        }
    }

    long long answer;
    for (long long i = 0; i < N; i++)
    {
        answer += dp[i];
    }

    cout << answer;
}