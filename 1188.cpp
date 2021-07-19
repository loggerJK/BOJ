#include <iostream>

using namespace std;

int main()
{
    int N = 0, M = 0;
    cin >> N >> M;

    int cnt = 0;
    int k = 0;
    for (int i = 0; i < M; i++) // M번 반복한다
    {
        k += N;
        if (k % M == 0)
            continue;
        else
        {
            ++cnt;
        }
    }

    cout << cnt;
}