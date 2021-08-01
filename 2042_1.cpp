/*
2042 : 구간 합 구하기
세그먼트 트리
*/
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define number 1000000007
using namespace std;

/*
리프 노드의 개수는 N개
*/
vector<ll> segTree(20000000); // 2* 10^7개, 0으로 초기화

ll N = 0, M = 0, K = 0, max_size = 0, max_leaf = 0;

// b번째 수를 c로 바꾼다
// index = b-1 to c
void update(ll b, ll c)
{
    ll idx = (max_leaf - 1) + b;
    // 리프 노드 바꾸기
    segTree[idx] = c;
    // 루트 노드들을 위로 업데이트 해나간다
    for (ll i = idx / 2; i >= 1; i = i / 2)
    {
        segTree[i] = (segTree[2 * i] % number) * (segTree[2 * i + 1] % number) % number;
    }
}

// sum [b:c]
//  원하는 인덱스, 해당 노드의 범위 인덱스, 노드 번호
ll getSum(ll b, ll c, ll cur_idx1, ll cur_idx2, ll cur_node)
{
    if (b == cur_idx1 && c == cur_idx2)
    {
        return segTree[cur_node];
    }
    ll mid = (cur_idx1 + cur_idx2) / 2;
    if (c <= mid)
    {
        // 왼쪽으로 몰려있는 경우
        return getSum(b, c, cur_idx1, mid, 2 * cur_node);
    }
    else if (mid < b)
    {
        // 오른쪽으로 몰려있는 경우
        return getSum(b, c, mid + 1, cur_idx2, 2 * cur_node + 1);
    }
    else
    {
        // 걸쳐있는 경우
        return (getSum(b, mid, cur_idx1, mid, 2 * cur_node) % number) * (getSum(mid + 1, c, mid + 1, cur_idx2, 2 * cur_node + 1) % number) % number;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    max_leaf = pow(2, ceil(log(((double)N)) / log(2.0)));

    // 리프 노드들 값을 입력, N개
    for (ll idx = max_leaf; idx <= max_leaf + N - 1; idx++)
    {
        ll input = 0;
        cin >> input;
        segTree[idx] = input;
    }

    // build whole segment tree
    for (ll idx = max_leaf - 1; idx >= 1; idx--)
    {
        segTree[idx] = (segTree[2 * idx] % number) * (segTree[2 * idx + 1] % number) % number;
    }

    for (ll i = 0; i < M + K; i++)
    {
        ll a = 0, b = 0;
        ll c = 0;
        cin >> a >> b >> c;

        if (a == 1)
        {
            // change b to c
            update(b, c);
        }
        else if (a == 2)
        {
            // get sum [b:c]
            cout << getSum(b, c, 1, max_leaf, 1) << "\n";
        }
    }
}
