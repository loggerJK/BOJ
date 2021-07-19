#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct node
{
    int number;
    int visited;
    struct node *link;

} Node;
// number of Vertices and Edges
int V = 0, E = 0;
vector<Node> vertex;
queue<Node> Queue;
int count = 0;

void insert(int u, int v)
{
    // initializaiton
    Node *newPtr = (Node *)malloc(sizeof(Node));
    newPtr->number = v;
    newPtr->visited = 0;
    newPtr->link = NULL;

    newPtr->link = vertex[u].link;
    vertex[u].link = newPtr;
}

void BFS()
{
    Queue.push(vertex[1]);
    vertex[1].visited = 1;
    while (Queue.empty() == false)
    {
        Node node = Queue.front();
        Queue.pop();
        count++;

        Node *iter = node.link;
        while (iter != NULL)
        {
            if (vertex[iter->number].visited == 0) // if WHITE
            {
                vertex[iter->number].visited = 1; // GRAY
                Queue.push(vertex[iter->number]);
            }
            iter = iter->link;
        }
        vertex[node.number].visited = 2;
    }
}
int main()
{
    // get the number of Vertex and Edges
    scanf("%d %d", &V, &E);
    // initialization
    for (int i = 0; i < V + 1; i++)
    {
        Node newNode;
        newNode.number = i;
        newNode.visited = 0;
        newNode.link = NULL;
        vertex.push_back(newNode);
    }
    // for (int i = 1; i < V + 1; i++)
    // {
    //     printf("vertex[%d] = %d\n", i, vertex[i].number);
    // }

    // insert edge
    for (int i = 0; i < E; i++)
    {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        insert(u, v); // (u,v)
        insert(v, u);
    }
    BFS();
    printf("%d", count - 1);
}