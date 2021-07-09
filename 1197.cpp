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

long long weight_of_MST = 0;

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
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
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
    // 총 v+1개, vertice[0]는 더미 데이터
    for (int i = 0; i <= V; i++)
    {
        vertex tmp;
        tmp.num = i;
        tmp.key = INF;
        vertice.push_back(tmp);
    }

    // adj_list initilization
    // 총 v+1개, adj_list[0]는 더미 데이터
    for (int i = 0; i <= V; i++)
    {
        vector<pair<int, int>> tmp;
        adj_list.push_back(tmp);
    }

    for (int i = 0; i <= V; i++)
    {
        MST_nodes_list.push_back(false);
    }

    // E개의 edge를 삽입, 쌍방향이라는 것에 주의할 것
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

    // 1번 노드부터 시작
    vertice[1].key = 0;
    MST_nodes_list[1] = true;

    // priority queue initilization
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    // 시작(노드=1번노드)와 연결된 간선들을 push 한다
    for (int i = 0; i < adj_list[1].size(); i++)
    {
        pq.push(adj_list[1][i]);
    }

    /*노드의 중복 삽입 문제 --> 정점이 방문되었는지 확인함으로써 해결한다*/

    while (!pq.empty())
    {
        // 가장 가중치가 낮은 간선을 고른다
        pair<int, int> edge;
        edge = pq.top();
        pq.pop();

        int TO = 0;
        TO = edge.first;

        // 이미 방문한 정점이라면 다시 고른다
        if (MST_nodes_list[TO] == true)
            continue;
        // 해당 노드는 이후 MST에 포함되는 것이 확실하므로, MST_nodes_list의 값을 true로 변경한다
        MST_nodes_list[TO] = true;

        // MST weight를 갱신한다
        weight_of_MST += edge.second;

        //TO의 인접 노드들에 대해서 가중치 갱신을 수행한다
        vector<pair<int, int>>::iterator iter;
        for (iter = adj_list[TO].begin(); iter != adj_list[TO].end(); iter++)
        {
            pair<int, int> v = (*iter);
            int j = v.first;
            int weight = v.second;
            // MST에 아직 포함되지 않은 노드라면, 큐에 간선을 push한다
            if (MST_nodes_list[j] == false)
            {
                pq.push(v);
            }
        }
    }

    cout << weight_of_MST;
}