/* https://www.acmicpc.net/problem/1260 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define size_ 10001
typedef struct
{
    int num;
    bool visited;
} node;

int N = 0,
    M = 0,
    V = 0;
/* 
정점의 개수 N
간선의 개수 M
탐색을 시작할 정점의 번호 V
 */
bool vertex[size_][size_]; /* 간선 정보를 저장할 배열 선언 */
node array[size_];

int main()
{
    /* N M V 입력 */
    scanf("%d %d %d", &N, &M, &V);

    /* 전역변수 및 배열 초기화 */
    for (int i = 0; i < size_; i++)
    {
        array[i].num = i;
        array[i].visited = false;
        for (int j = 0; j < size_; j++)
            vertex[i][j] = false;
    }

    /* 간선 정보 입력, 간선은 양방향 */
    for (int i = 0; i < M; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        vertex[a][b] = vertex[b][a] = true;
    }

    /* DFS 시작 */
    /* 스택 생성 */
    stack<node *> s;
    s.push(&array[V]);

    while (!s.empty())
    {
        /* 노드 정보를 출력한다 */
        node *Node = s.top();
        s.pop();
        if (!Node->visited)
            Node->visited = true;
        else
            continue;
        int num = Node->num;
        printf("%d ", num);
        /* 방문처리 */

        /* 자식들을 스택에 insert */
        for (int i = N; i >= 1; i--)
        {
            /* num에서 i로 가는 간선이 존재하고 */
            if (vertex[num][i])
                /* 아직 방문하지 않은 노드라면 */
                if (array[i].visited == false)
                    /* i번 노드를 push 한다 */
                    s.push(&array[i]);
        }
    }
    printf("\n");
    /* BFS 시작 */
    queue<node *> q;
    q.push(&array[V]);
    /* 전역변수 및 배열 초기화 */
    for (int i = 0; i < size_; i++)
    {
        array[i].num = i;
        array[i].visited = false;
    }

    while (!q.empty())
    {
        /* 노드 정보를 출력한다 */
        node *Node = q.front();
        q.pop();
        /* 방문처리, 이미 방문한 노드라면 탈출한다 */
        if (!Node->visited)
            Node->visited = true;
        else
            continue;
        int num = Node->num;
        printf("%d ", num);
        /* 방문처리 */

        /* 자식들을 스택에 insert */
        for (int i = 1; i <= N; i++)
        {
            /* num에서 i로 가는 간선이 존재하고 */
            if (vertex[num][i])
                /* 아직 방문하지 않은 노드라면 */
                if (array[i].visited == false)
                    /* i번 노드를 push 한다 */
                    q.push(&array[i]);
        }
    }
    // system("pause");
}