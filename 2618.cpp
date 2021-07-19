#include <iostream>
#define maxW 1000
#define pii pair<int, int>
using namespace std;

int N = 0, W = 0;

pii accident[maxW + 1];
// 사건은 1번째 사건 ~ W번째 사건
int dp[maxW + 1][maxW + 1];
/* 
dp[a][b]
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

int compute_dp(int a, int b)
{
    // dp[a][b]를 구해서 저장하는 프로그램 recursively
    /* 
    min dp[i][W], dp[W][i] (i = 0 to W-1), 경로 W까지의 최솟값,
    a > b 인 경우
    dp[a+1][b] =              BAAAAAA
    dp[a][b] + A
    dp[a][b+1] =              BBAAAAA
    dp[a-1][b+1]
     */
    if (a >= (b + 2))
    {
        dp[a][b] = dp[a - 1][b] + move(A, a - 1, a);
    }
    else if (a == (b + 1))
    {
        min(dp[0][b] + move(A, 0, a), dp[1][b] + move(A, 1, a), dp[b - 1][b] + move(A, b - 1, a));
    }
    else if ((a + 1) == b)
    {
    }
    else if ((a + 2) <= b)
    {
        dp[a][b] = dp[a][b - 1] + move(B, b - 1, b);
    }
}

int main()
{
    cin >> N >> W;

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

    compute_dp(W)(W);
}