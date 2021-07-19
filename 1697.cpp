#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

#define MAX 100001
#define White 0
#define Gray 1
#define Black 2
using namespace std;

int N = 0, K = 0;
typedef struct node
{
    int num;
    int visit;
    int distance;

} Node;
vector<Node> vec;
queue<Node> Queue;

void BFS(int i)
{
    vec[i].visit = Gray;
    vec[i].distance = 0;
    Queue.push(vec[i]);
    while (!Queue.empty())
    {
        Node data = Queue.front();
        int i = data.num;
        Queue.pop();
        int arr[3] = {i - 1, i + 1, 2 * i};
        for (int j = 0; j < 3; j++)
        {
            int index = arr[j];
            if (0 <= index && index < MAX && vec[index].visit == White)
            {
                vec[index].distance = vec[i].distance + 1;
                vec[index].visit = Gray;
                Queue.push(vec[index]);
            }
        }
        vec[i].visit = Black;
    }
}
int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < MAX; i++)
    {
        Node _vec;
        _vec.num = i;
        _vec.visit = White;
        _vec.distance = 0;
        vec.push_back(_vec);
    }

    BFS(N);
    printf("%d", vec[K].distance);
}