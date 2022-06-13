// Dijkstra Algorithm

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 99999
#define white 0
#define black 1
using namespace std;
int N = 0, M = 0;
struct node
{
    int x;
    int y;
    char val; // 0과 1을 저장할 변수
    int d;    // (0,0) 부터의 최단거리
    char visit;
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.d > b.d;
    }
};
priority_queue<node, vector<node>, cmp> pq;
vector<vector<node>> Node; // 2차원 배열 matrix
vector<pair<int, int>> a;
void Dijkstra(int x, int y);

int main()
{
    scanf("%d %d", &M, &N);
    a.push_back(make_pair(1, 0));
    a.push_back(make_pair(0, -1));
    a.push_back(make_pair(-1, 0));
    a.push_back(make_pair(0, 1));
    for (int i = 0; i < N; i++)
    {
        vector<node> vec;
        Node.push_back(vec);
        for (int j = 0; j < M; j++)
        {
            // 변수 초기화
            node n;
            n.x = i;
            n.y = j;
            char c = 0;
            cin >> c;
            n.val = c - '0';
            n.d = INF;
            n.visit = white;
            // 배열 삽입
            Node[i].push_back(n);
        }
    }
    // for (int i = 0; i < N; i++)
    // {

    //     for (int j = 0; j < M; j++)
    //         printf("%d ", Node[i][j].val);
    //     printf("\n");
    // }

    Dijkstra(0, 0);
    // for (int i = 0; i < N; i++)
    // {

    //     for (int j = 0; j < M; j++)
    //         printf("%d\t", Node[i][j].d);
    //     printf("\n");
    // }
    printf("%d", Node[N - 1][M - 1].d);
}

void Dijkstra(int x, int y)
{
    // init starting point
    Node[x][y].visit = white;
    Node[x][y].d = 0;
    pq.push(Node[x][y]);
    while (!pq.empty())
    {
        // pop
        node &n = Node[pq.top().x][pq.top().y];
        pq.pop();
        if (n.visit == black)
            continue;
        // update adjacent and push if updated
        for (int i = 0; i < 4; i++)
        {
            int new_x = n.x + a[i].first;
            int new_y = n.y + a[i].second;
            if (0 <= new_x && new_x < N && 0 <= new_y && new_y < M)
            {
                node &n2 = Node[new_x][new_y];
                if (n2.visit == black)
                    continue;
                if (n2.val == 1)
                {
                    if (n2.d > n.d + 1)
                    {
                        n2.d = n.d + 1;
                        pq.push(n2);
                    }
                }

                else if (n2.val == 0)
                    if (n2.d > n.d)
                    {
                        n2.d = n.d;
                        pq.push(n2);
                    }
            }
        }
        // make n black
        n.visit = black;
    }
}