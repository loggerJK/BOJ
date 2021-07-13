#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int c = 0;

typedef struct node
{
    int visit;

} Node;

void search(Node arr[], int node_num, int tree_num, int print[], int N, int M);

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    Node arr[8 + 1]; // 8개의 노드 생성

    for (int i = 0; i <= 8; i++)
    {
        arr[i].visit = 0;
    }

    int print[8 + 1]; // 8개의 depth까지 저장 가능한 출력용 배열

    for (int i = 1; i <= N; i++)
    {
        search(arr, i, 1, print, N, M); // i를 시작 노드로 하여 DFS 시작
    }
}

void search(Node arr[], int node_num, int tree_num, int print[], int N, int M)
{
    print[tree_num] = node_num; // 출력용 배열에 노드 넘버 추가

    if (tree_num == M)
    { // 끝노드라면 프린트 & 방문X & 서칭 종료
        if (c == 0)
        {
            for (int i = 1; i <= M; i++)
            {
                printf("%d ", print[i]);
                c = 1;
            }
        }
        else
        {
            printf("\n");
            for (int i = 1; i <= M; i++)
            {
                printf("%d ", print[i]);
            }
        }
        return;
    }

    arr[node_num].visit = 1; // 방문 처리

    for (int i = 1; i <= N; i++)
    { // N까지의 노드 방문여부 검사 && 방문하지 않았다면 방문
        if (arr[i].visit == 0)
        {
            search(arr, i, tree_num + 1, print, N, M);
        }
    }

    arr[node_num].visit = 0; // 다시 방문X로 설정
}