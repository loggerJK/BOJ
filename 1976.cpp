#include <iostream>

using namespace std;

int adj_matrix[201][201];
int N = 0, M = 0;

int parent[201];
void merge(int a, int b);
int find_root(int a);

void merge(int a, int b)
{
    int root_a = 0, root_b = 0;
    root_a = find_root(a);
    root_b = find_root(b);
    if (root_a == root_b)
        return;
    else
        // b의 루트를 a의 루트로 설정한다
        // b 집합이 a 집합으로 붙게 된다
        parent[root_b] = root_a;
}

int find_root(int a)
{
    if (parent[a] < 0)
        return a;
    else
    {
        // path compression
        parent[a] = find_root(parent[a]);
        return parent[a];
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // init
    for (int i = 0; i < 201; i++)
        parent[i] = -1;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int connected_info = 0;
            cin >> connected_info;
            adj_matrix[i][j] = connected_info;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int connected = 0;
            connected = adj_matrix[i][j];
            if (connected == 0)
            {
                continue;
            }
            else if (connected == 1)
            {
                // 두 노드가 연결되어 있으므로 하나의 집합으로 합친다
                merge(i, j);
            }
        }

    int root = 0;
    bool possible = true;
    for (int i = 0; i < M; i++)
    {
        int city = 0;
        cin >> city;
        // 처음에는 info 저장
        if (i == 0)
            root = find_root(city);
        else
        {
            int root_of_city = 0;
            root_of_city = find_root(city);
            if (root != root_of_city)
            {
                possible = false;
                break;
            }
        }
    }

    if (possible)
        cout << "YES";
    else
        cout << "NO";
}
