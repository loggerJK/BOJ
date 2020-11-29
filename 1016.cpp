#include <stdio.h>
#include <iostream>
#include <cmath>
#define ll long long
#define d_106 1000000 // 10^
using namespace std;

ll MIN = 0, MAX = 0;
bool arr[d_106 + 1]; // 0 ~ 10^6

int main()
{
    cin >> MIN >> MAX;

    // 초기화, 최대 10^6번 루프
    for (ll i = MIN; i <= MAX; i++)
        arr[i - MIN] = true;

    ll SQRT = sqrt(MAX);
    for (int k = 2; k <= SQRT; k++)
    {
        // i = (어떤 정수)^2
        // i, j 초기화
        ll i = pow(k, 2);
        ll j = 0;
        if (MIN % i == 0)
            j = MIN / i;
        else
            j = MIN / i + 1;

        // i의 배수들을 비활성화한다
        for (; i * j <= MAX; j++)
        {
            arr[i * j - MIN] = false;
        }
    }

    ll cnt = 0;
    for (ll i = MIN; i <= MAX; i++)
    {
        if (arr[i - MIN])
        {
            // cout << i - MIN;
            ++cnt;
        }
    }
    // cout << "\n";
    cout << cnt;
}