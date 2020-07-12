/* 
기본적으로 BFS를 이용한다
원래의 수도코드는 d[v]를 이용하지만
지금은 d[v][block]을 이용해서 경로를 3차원으로 구현한다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
#define White 0
#define Gray 1
#define Black 2
#define MaxD 3000
int N = 0,
    M = 0;
int MIN(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
typedef struct node
{
    int x;
    int y;
    int cur_d;      // 노드가 pop되었을때의 경로가 0경로인가 1경로인가, 기본값은 0
    int value;      // 0 or 1
    int visited[2]; // '0경로'의 방문인가 '1경로'의 방문인가
    int d[2];       // distance version이 두개!
} Node;
void Push(vector<vector<Node>> *mPtr, int i, int j, int cur_val, int cur_d, int distance);
queue<Node> Queue;

void BFS(vector<vector<Node>> *mPtr, int i, int j)
{
    // init
    (*mPtr)[i][j].d[0] = 1; // '0경로' 초기화

    (*mPtr)[i][j].visited[0] = Gray; //
    int cur_d = 0;                   // 논블럭으로 시작
    Queue.push((*mPtr)[i][j]);
    while (!Queue.empty())
    {
        // pop
        Node data = Queue.front();
        Queue.pop();
        int x = data.x;
        int y = data.y;
        int cur_val = data.value;
        int cur_d = data.cur_d;
        //process
        //push
        Push(mPtr, x - 1, y, cur_val, cur_d, data.d[cur_d]);
        Push(mPtr, x + 1, y, cur_val, cur_d, data.d[cur_d]);
        Push(mPtr, x, y - 1, cur_val, cur_d, data.d[cur_d]);
        Push(mPtr, x, y + 1, cur_val, cur_d, data.d[cur_d]);
        //visitied
        (*mPtr)[i][j].visited[cur_d] = Black;
    }
}
void Push(vector<vector<Node>> *mPtr, int i, int j, int cur_val, int cur_d, int distance)

{
    if (0 <= i && i < N && 0 <= j && j < M)
    {
        int next_val = (*mPtr)[i][j].value;
        if ((*mPtr)[i][j].visited[cur_d] == White)
        {
            if (cur_val == 0 && next_val == 0)
            {
                (*mPtr)[i][j].visited[cur_d] = Gray;
                (*mPtr)[i][j].cur_d = cur_d;
                (*mPtr)[i][j].d[cur_d] = distance + 1;
                Queue.push((*mPtr)[i][j]);
            }
            else if (cur_val == 0 && next_val == 1 && cur_d == 0)
            {
                (*mPtr)[i][j].visited[1] = Gray;
                (*mPtr)[i][j].cur_d = 1;
                (*mPtr)[i][j].d[1] = distance + 1;
                Queue.push((*mPtr)[i][j]);
            }
            else if (cur_val == 1 && next_val == 0)
            {
                (*mPtr)[i][j].visited[1] = Gray;
                (*mPtr)[i][j].cur_d = 1;
                (*mPtr)[i][j].d[1] = distance + 1;
                Queue.push((*mPtr)[i][j]);
            }
        }
    }
}

int main()
{
    // input is N M
    scanf("%d %d", &N, &M);

    // Node node1 = {1, {2, 3}, 4};
    // printf("%d %d %d %d", node1.value, node1.d[0], node1.d[1], node1.color);

    // make N*M Matrix
    vector<vector<Node>> matrix(N, vector<Node>(M, {0, 0, 0, 0, {White, White}, {MaxD, MaxD}}));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            matrix[i][j].x = i;
            matrix[i][j].y = j;
            char c = 0;
            do
            {
                c = getchar();
            } while (c == '\n');
            matrix[i][j].value = c - '0';
        }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         printf("%d ", matrix[i][j].value);
    //     }
    //     printf("\n");
    // }

    // Input으로 value 초기화하기
    BFS(&matrix, 0, 0);
    int result = MIN(matrix[N - 1][M - 1].d[0], matrix[N - 1][M - 1].d[1]);
    printf("%d ", (result == 3000) ? -1 : result);
}