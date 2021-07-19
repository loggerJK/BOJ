/*
    - Dijkstra 응용
    */
#include <iostream>
#include <queue>
#define INF -1

using namespace std;

// global variables

int N = 0, M = 0, departure = 0, arrival = 0;
/* 
    N : number of node(city)
    M : number of edge info
    */

typedef struct edge
{
    int city_num;
    long long weight;
};

vector<vector<edge>> adj_list;
/* 
    - adj_list[i][j] = C
    i -> j 경로의 weight는 C
    */

typedef struct city
{
    bool visited;
    long long maximum_weight;
};

city city_list[100001];

// 내림차순
typedef struct comp
{
    bool operator()(int &a, int &b)
    {
        return city_list[a].maximum_weight < city_list[b].maximum_weight;
    }
};

long long MIN(long long &a, long long &b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // init global variables
    for (int n = 0; n <= N; n++)
    {
        vector<edge> vec;
        adj_list.push_back(vec);
        city_list[n].visited = false;
        city_list[n].maximum_weight = INF;
    }

    // get inputs & graph informations

    for (int m = 0; m < M; m++)
    {
        int A = 0, B = 0, C = 0;
        cin >> A >> B >> C;
        edge first_edge; // A-> B
        first_edge.city_num = B;
        first_edge.weight = C;
        adj_list[A].push_back(first_edge);
        edge second_edge;
        second_edge.city_num = A; // B -> A
        second_edge.weight = C;
        adj_list[B].push_back(second_edge);
    }

    cin >> departure >> arrival;

    // start dijkstra from 'departure'
    priority_queue<int, vector<int>, comp> pq;
    // 노드 번호만을 담는 우선순위 큐
    pq.push(departure);
    city_list[departure].maximum_weight = 9999999999;

    while (!pq.empty())
    {
        int visiting_city_num = 0;
        visiting_city_num = pq.top();
        pq.pop();

        // 이미 방문한 노드는 방문하지 않는다
        if (city_list[visiting_city_num].visited == true)
            continue;
        else
            // 방문처리
            city_list[visiting_city_num].visited = true;

        // 인접 노드 업데이트
        vector<edge>::iterator iter;
        for (iter = adj_list[visiting_city_num].begin(); iter != adj_list[visiting_city_num].end(); iter++)
        {
            edge adj_edge = (*iter); // 인접 city로의 edge
            int adj_city_num = 0;    // 인접 city 번호
            adj_city_num = adj_edge.city_num;

            // weight 업데이트
            long long prev_maximum_weight = city_list[visiting_city_num].maximum_weight;
            long long candidate_maximum_weight = MIN(prev_maximum_weight, adj_edge.weight);

            // 간선을 지나면서 최대 중량은 줄어드는데, 기존에 조사된 최대 중량보다는 큰 값인 경우 Update
            if (candidate_maximum_weight > city_list[adj_city_num].maximum_weight)
            {
                // update weight
                city_list[adj_city_num].maximum_weight = candidate_maximum_weight;
                // 업데이트 된 노드는 재탐색해야하므로 큐에 푸쉬
                pq.push(adj_city_num);
            }
        }
    }

    cout << city_list[arrival].maximum_weight;
}
