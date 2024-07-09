#include <iostream>
#include <vector>
#include <algorithm>
#define maxnum 999999
using namespace std;

int N = 0;
int maxDP[3] = {0, 0, 0};
int minDP[3] = {0, 0, 0};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a = 0, b = 0, c = 0;
        int maxDP_[3], minDP_[3];
        for (int i = 0; i < 3; i++)
        {
            maxDP_[i] = maxDP[i];
            minDP_[i] = minDP[i];
        }
        cin >> a >> b >> c;
        // maxDP 계산
        maxDP[0] = max(maxDP_[0], maxDP_[1]) + a;
        maxDP[1] = max(max(maxDP_[0], maxDP_[1]), maxDP_[2]) + b;
        maxDP[2] = max(maxDP_[1], maxDP_[2]) + c;
        // minDP 계산
        minDP[0] = min(minDP_[0], minDP_[1]) + a;
        minDP[1] = min(min(minDP_[0], minDP_[1]), minDP_[2]) + b;
        minDP[2] = min(minDP_[1], minDP_[2]) + c;
    }

    int answer_max = 0, answer_min = 0;
    answer_max = max(max(maxDP[0], maxDP[1]), maxDP[2]);
    answer_min = min(min(minDP[0], minDP[1]), minDP[2]);
    cout << answer_max << " " << answer_min;
}