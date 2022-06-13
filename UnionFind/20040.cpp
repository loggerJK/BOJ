#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, m = 0;

// root[i] = j : i -> j, i의 루트 = j
vector<int> root;

// x의 (최상단) 루트 노드를 반환
int find(int x)
{
    // x가 루트라면 자기 자신을 반환
    if (root[x] < 0)
        return x;

    // 경로 단축 (Path Suppression) -> 루트가 최상단루트가 되도록
    root[x] = find(root[x]);
    return root[x];
}

// y -> x
// merge의 결과가 cycle이면 true, 그렇지 않다면 false를 반환한다.
// 루트 노드를 찾아서
bool merge(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);

    if (root_x == root_y)
        return true;

    root[root_x] += root[root_y];
    //  root_y -> root_x
    root[root_y] = root_x;
    return false;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    // 유니온 파인드 초기화
    // 루트 노드일 경우에는 음수를 가지고 있다
    for (int i = 0; i < n; i++)
    {
        root.push_back(-1);
    }

    int first_cycle = 0;
    bool result = false;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int node1 = 0, node2 = 0;
        // 두 정점을 연결한다 (merge)
        cin >> node1 >> node2;
        result = merge(node1, node2);

        if (result && cnt == 0)
        {
            cnt++;
            first_cycle = i;
        }
    }

    cout << first_cycle;
    return 0;
}