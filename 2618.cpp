#include <iostream>
#include <cmath>
#define maxW 1000
#define very_big_num 987654321
#define pii pair<int, int>
using namespace std;

int N = 0, W = 0;

pii accident[maxW + 100];
// 사건은 1번째 사건 ~ W번째 사건
int dp[maxW + 100][maxW + 100];
/* 
dp[a][b]의 정의
A가 마지막으로 처리한 사건이 a번째 사건, B가 마지막으로 처리한 사건이 b번째 사건일때
ABAAABAAAB
BABABAABAB
BAAABBBBAB
등등등 중에서
최소 '최단거리의 합'

총 N^2번 dp배열을 모두 채우면 끝이난다

dp[0][W] dp[1][W] ... dp[W-1][W]
dp[W][0] dp[W][1] ... dp[W][W-1]
중에서의 최솟값

[0] :  처리한 사건 없음

경찰차 위치 초깃값
(1,1), (N,N)

 */

int move_A(int a, int b)
{
    if (a == 0)
        return abs(1 - accident[b].first) + abs(1 - accident[b].second);
    else
        return abs(accident[a].first - accident[b].first) + abs(accident[a].second - accident[b].second);
}

int move_B(int a, int b)
{
    if (a == 0)
        return abs(N - accident[b].first) + abs(N - accident[b].second);
    else
        return abs(accident[a].first - accident[b].first) + abs(accident[a].second - accident[b].second);
}

int compute_dp(int a, int b)
{
    // dp[a][b]를 구해서 저장하는 프로그램 recursively
    /* 
    min dp[i][W], dp[W][i] (i = 0 to W-1), 경로 W까지의 최솟값,
    a > b 인 경우
    dp[a+1][b] =              BAAAAAA
    dp[a][b] + A
    dp[a][b+1] =              BBAAAAA
    dp[a-1][b+1] + A
     */
    if (dp[a][b] != -1)
        return dp[a][b];

    if (a >= (b + 2))
    {
        dp[a][b] = compute_dp(a - 1, b) + move_A(a - 1, a);
    }
    else if (a == (b + 1))
    {
        int min_ = very_big_num;
        for (int i = 0; i <= b - 1; i++)
            if (min_ > (compute_dp(i, b) + move_A(i, a)))
                min_ = compute_dp(i, b) + move_A(i, a);
        dp[a][b] = min_;
    }
    else if ((a + 1) == b)
    {
        int min_ = very_big_num;
        for (int i = 0; i <= (a - 1); i++)
        {
            if (min_ > (compute_dp(a, i) + move_B(i, b)))
                min_ = compute_dp(a, i) + move_B(i, b);
        }
        dp[a][b] = min_;
    }
    else if ((a + 2) <= b)
    {
        dp[a][b] = compute_dp(a, b - 1) + move_B(b - 1, b);
    }

    return dp[a][b];
}

void print_way(int a, int b)
{
    if (a == 0)
    {
        for (int i = 0; i < b; i++)
            cout << "2\n";
        // cout << "a = " << a << " b = " << b << "\n";
        return;
    }

    if (b == 0)
    {
        for (int i = 0; i < a; i++)
            cout << "1\n";
        // cout << "a = " << a << " b = " << b << "\n";
        return;
    }

    if (a > b)
    {
        int min_a = 0, min_ = very_big_num;
        for (int i = 0; i < b; i++)
            if (min_ > compute_dp(i, b) + move_A(i, b + 1))
            {
                min_ = compute_dp(i, b) + move_A(i, b + 1);
                min_a = i;
            }
        print_way(min_a, b);
        for (int i = 0; i < a - b; i++)
            cout << "1\n";
    }
    if (a < b)
    {
        int min_b = 0, min_ = very_big_num;
        for (int i = 0; i < a; i++)
            if (min_ > compute_dp(a, i) + move_B(i, a + 1))
            {
                min_ = compute_dp(a, i) + move_B(i, a + 1);
                min_b = i;
            }
        print_way(a, min_b);
        for (int i = 0; i < b - a; i++)
            cout << "2\n";
    }
    // cout << "a = " << a << " b = " << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;

    // insert dummy data
    accident[0] = make_pair(-1, -1);
    for (int w = 1; w <= W; w++)
    {
        int i = 0, j = 0;
        cin >> i >> j;
        pii tmp;
        tmp.first = i;
        tmp.second = j;
        accident[w] = tmp;
    }

    for (int i = 0; i < maxW + 100; i++)
        for (int j = 0; j < maxW + 100; j++)
        {
            dp[i][j] = -1; // 초기값을 -1로 설정한다
        }

    // base case 설정
    dp[0][1] = abs(N - accident[1].first) + abs(N - accident[1].second);
    dp[1][0] = abs(1 - accident[1].first) + abs(1 - accident[1].second);

    int min_ = very_big_num, min_a = 0, min_b = 0;
    for (int i = 0; i < W; i++)
    {
        if (min_ > compute_dp(i, W))
        {
            min_ = compute_dp(i, W);
            min_a = i;
            min_b = W;
        }
        if (min_ > compute_dp(W, i))
        {
            min_ = compute_dp(W, i);
            min_a = W;
            min_b = i;
        }
    }
    cout << min_ << "\n";
    // cout << "min_a = " << min_a << " min_b = " << min_b << "\n";

    // 경로 출력
    print_way(min_a, min_b);
}