#include <vector>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// typedef struct edge
// {
//     int node[2];
//     int dist;
// }
vector<int> root;
class edge
{
public:
    // 멤버 변수 선언
    int node[2];
    int dist;
    // 생성자 선언
    edge(int a, int b, int dist)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->dist = dist;
    }
};

vector<edge> edge_vec;

int N = 0, M = 0;

// 루트 노드를 찾는 함수
int find(int a)
{
    if (root[a] < 0)
        return a;

    // 경로 압축
    return root[a] = find(root[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        // 크기 정보를 합친다
        root[a] += root[b];
        // b -> a
        root[b] = a;
    }
}

bool compare(edge a, edge b)
{
    return a.dist < b.dist;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        root.push_back(-1);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;

        // a와 b가 같은 간선은 제외한다
        if (a != b)
            edge_vec.push_back(edge(a, b, dist));
    }

    // 비용 기준 정렬
    sort(edge_vec.begin(), edge_vec.end(), compare);

    int cost = 0;
    int edge_count = 0;
    for (auto iter : edge_vec)
    {
        // 간선을 선택한다

        // 사이클이 만들어지는지 확인한다
        if (find(iter.node[0]) == find(iter.node[1]))
            continue;

        // 사이클이 만들어지지 않는다면 연결한다
        merge(iter.node[0], iter.node[1]);
        cost += iter.dist;
        edge_count++;

        if (edge_count == (N - 1))
            break;
    }

    // 총 비용을 출력한다

    cout << cost;
}