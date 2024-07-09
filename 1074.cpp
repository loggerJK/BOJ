#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;

int DFS(int r, int c, int N)
{
    if (N == 1)
    {
        return (2 * r + c);
    }
    if (r < pow(2, N - 1) && c < pow(2, N - 1))
    {
        // case 0
        return DFS(r, c, N-1);
    }
    else if (r < pow(2, N - 1) && c >= pow(2, N - 1))
    {
        // case 1
        return pow(4, N-1) + DFS(r, c - pow(2, N -1 ), N - 1);
    }
    else if (r >= pow(2, N - 1) && c < pow(2, N - 1))
    {
        // case 2
        return 2 * pow(4, N - 1) + DFS(r - pow(2, N - 1), c, N - 1);
    }
    else if (r >= pow(2, N - 1) && c >= pow(2, N - 1))
    {
        // case 3
        return 3 * pow(4, N - 1) + DFS(r - pow(2, N - 1), c - pow(2, N - 1), N - 1);
    }
}
int main()
{
    cin >> N >> r >> c;

    // N = 1이 될때까지 호출
    int result = DFS(r, c, N);

    cout << result;
}