
#include <iostream>
#include <vector>
#include <cassert>
#define SIZE 9999999
int parent[SIZE];

using namespace std;

void merge(int a, int b);
int find_root(int a);
bool same(int a, int b);

int find_root(int a)
{
    // 1. 자식노드일 경우 루트를 반환
    // 2. 루트 노드일 경우 집합의 크기를 반환, 아직 구현 X
    if (parent[a] < 0)
        return a;
    // path compression
    parent[a] = find_root(parent[a]);
    return parent[a];
}

void merge(int a, int b)
{
    // 두 집합을 하나로 합친다
    // '한 노드의 루트'의 루트가 다른 집합의 루트가 되도록 설정한다
    // b -> a merge

    if (a == b)
        return;
    int root_a = find_root(a);
    int root_b = find_root(b);
    // 만약 같은 집합이라면 굳이 merge를 시행하지 않는다
    // 같은 집합인데 merge한다면 괜히 트리의 높이만 높아지는 의미가 되기 때문
    if (root_a == root_b)
        return;
    parent[root_b] = root_a;
}

bool same(int a, int b)
{
    // 같은 집합 내에 있는지 비교한다
    int root_a = find_root(a);
    int root_b = find_root(b);
    if (root_a == root_b)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0;

    cin >> n >> m;

    for (int i = 0; i < SIZE; i++)
        // 음수로 초기화
        parent[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int calculate = 0, a = 0, b = 0;
        cin >> calculate >> a >> b;
        if (calculate == 0)
            merge(a, b);
        else if (calculate == 1)
        {
            bool yes_or_no = false;
            yes_or_no = same(a, b);
            if (yes_or_no)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}