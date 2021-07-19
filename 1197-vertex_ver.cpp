#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 99999999

using namespace std;

typedef struct vertex
{
    int num;
    int key;
};

long int weight_of_MST = 0;

vector<vertex> vertice;
/*
    vertice[i] : i번째 vertex
    */
vector<vector<pair<int, int>>> adj_list;
/*
    adj_matrix[i] : 출발점이 i인 edge들의 집합
    adj_matrix[i].first : 도착점 (j)
    adj_matrix[i].second : (i,j)의 가중치
    */

vector<bool> MST_nodes_list;

// 가중치가 적은 것들의 우선순위가 높다
// 즉, 오름차순 정렬
struct comp
{
    bool operator()(int &a, int &b)
    {
        return vertice[a].key > vertice[b].key;
    }
};

int main()
{
    int V = 0, E = 0;
    /*
    V : vertex의 개수
    E : edge의 개수
    */
    cin >> V >> E;

    // 초기화

    // vertice initilization
    for (int i = 0; i <= V; i++)
    {
        vertex tmp;
        tmp.num = i;
        tmp.key = INF;
        vertice.push_back(tmp);
    }

    // adj_matrix initilization
    for (int i = 0; i <= E; i++)
    {
        vector<pair<int, int>> tmp;
        adj_list.push_back(tmp);
    }

    for (int i = 0; i <= V; i++)
    {
        MST_nodes_list.push_back(false);
    }

    for (int i = 0; i < E; i++)
    {
        int u = 0, v = 0, w = 0; // 출발점, 도착점, 가중치
        cin >> u >> v >> w;
        pair<int, int> pii;
        pii.first = v;
        pii.second = w;
        adj_list[u].push_back(pii);
        pair<int, int> pii2;
        pii2.first = u;
        pii2.second = w;
        adj_list[v].push_back(pii2);
    }

    // 1번째 노드부터 시작하자
    vertice[1].key = 0;

    // priority queue initilization
    priority_queue<int, vector<int>, comp> pq;
    pq.push(1);

    while (!pq.empty())
    {
        // 가장 가중치가 낮은 노드 u를 고른다
        int u = 0;
        u = pq.top();
        pq.pop();

        // cout << u;

        if (MST_nodes_list[u] == true)
            continue;
        // 이 노드 u는 이후 MST에 포함되는 것이 확실하므로, MST_nodes_list의 값을 true로 변경한다
        MST_nodes_list[u] = true;

        // 인접 노드들에 대해서 가중치 갱신을 수행한다
        vector<pair<int, int>>::iterator iter;
        for (iter = adj_list[u].begin(); iter != adj_list[u].end(); iter++)
        {
            pair<int, int> v = (*iter);
            int j = v.first;
            int weight = v.second;
            if (MST_nodes_list[j] == false && weight < vertice[j].key)
            {
                vertice[j].key = weight;
                pq.push(j);
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        weight_of_MST += vertice[i].key;
    }

    cout << weight_of_MST;
}