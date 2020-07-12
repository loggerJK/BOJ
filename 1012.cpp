#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
int N = 0, M = 0, K = 0;

typedef struct node
{
    int x;
    int y;
    int value;
    int visited;
} Node;
void Push(vector<vector<Node>> *vPtr, stack<Node> *sPtr, int i, int j)
{
    if (0 <= i && i < N && 0 <= j && j < M)
    {
        if ((*vPtr)[i][j].visited == WHITE && (*vPtr)[i][j].value == 1)
        {
            (*vPtr)[i][j].visited = GRAY;
            (*sPtr).push((*vPtr)[i][j]);
        }
    }
}
void DFS(vector<vector<Node>> *vPtr, int i, int j)
{
    stack<Node> Stack;
    Stack.push((*vPtr)[i][j]);
    (*vPtr)[i][j].visited = GRAY;
    while (!Stack.empty())
    {
        // pop
        Node newNode = Stack.top();
        Stack.pop();
        i = newNode.x;
        j = newNode.y;
        //process
        // push Adjacent if condition is satisfied
        Push(vPtr, &Stack, i - 1, j);
        Push(vPtr, &Stack, i + 1, j);
        Push(vPtr, &Stack, i, j - 1);
        Push(vPtr, &Stack, i, j + 1);
        // color to white
        (*vPtr)[i][j].visited = BLACK;
    }
    return;
}

int main()
{
    int TC = 0; // number of Test Case
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        // printf("\n----------------------\n");
        scanf("%d %d %d", &N, &M, &K);
        //declare N*M matrix by array
        vector<vector<Node>> matrix;
        //init
        for (int i = 0; i < N; i++)
        {
            vector<Node> vec;
            for (int j = 0; j < M; j++)
            {
                Node newNode;
                newNode.x = i;
                newNode.y = j;
                newNode.value = 0;
                newNode.visited = 0;
                vec.push_back(newNode);
            }
            matrix.push_back(vec);
        }
        // setting value 1
        for (int k = 0; k < K; k++)
        {
            int i = 0, j = 0;
            scanf("%d %d", &i, &j);
            matrix[i][j].value = 1;
        }
        int cnt = 0;
        // search all nodes by DFS
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j].visited == WHITE && matrix[i][j].value == 1)
                {
                    DFS(&matrix, i, j);
                    ++cnt;
                }
            }
        printf("%d\n", cnt);
    }
}