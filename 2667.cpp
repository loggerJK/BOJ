#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef struct node
{
    int x;
    int y;
    int value;
    int visited;
} Node;
int N = 0;
vector<vector<Node>> map;
stack<Node> Stack;
void Push(int i, int j)
{
    if (i < 0 || N <= i || j < 0 || N <= j)
        return;
    else
    {
        if (map[i][j].visited == 0 && map[i][j].value == 1)
        {
            Stack.push(map[i][j]);
            map[i][j].visited = 1;
            return;
        }
    }
}
int DFS(int i, int j)
{
    // init
    map[i][j].visited = 1; // GRAY
    Stack.push(map[i][j]);
    int cnt = 0;
    while (!Stack.empty())
    {
        // pop
        Node topNode = Stack.top();
        Stack.pop();
        i = topNode.x;
        j = topNode.y;
        // process
        cnt++;
        // push Adjacent
        // if 0 <= i && i < N && 0 <= j && j < N
        Push(i - 1, j);
        Push(i + 1, j);
        Push(i, j - 1);
        Push(i, j + 1);
        // color to Black
        map[i][j].visited = 2;
    }
    return cnt;
}
int main()
{
    // the size of Map is N * N
    scanf("%d", &N);

    // declare variable 'map' N*N
    vector<int> counter;
    for (int i = 0; i < N; i++)
    {
        vector<Node> maprow;
        for (int j = 0; j < N; j++)
        {
            Node newNode;
            newNode.x = i;
            newNode.y = j;
            newNode.value = 0;
            newNode.visited = 0;
            char c = 0;
            do
            {
                c = getchar();
            } while (c == 10);
            newNode.value = (int)(c - '0');
            // scanf("%d", &(newNode.value));
            maprow.push_back(newNode);
        }
        map.push_back(maprow);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j].visited == 0 && map[i][j].value == 1)
            {
                // White인 경우에만 DFS를 실행한다
                int c = 0;
                c = DFS(i, j);
                counter.push_back(c);
            }
        }
    }
    sort(counter.begin(), counter.end());
    printf("%ld\n", counter.size());
    for (vector<int>::iterator v = counter.begin(); v != counter.end(); v++)
    {
        printf("%d\n", *v);
    }
}