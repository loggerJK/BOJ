#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define maxV 2010
#define maxE 50010
#define INF 999999999
#define white 0
#define black 1
#define pii pair<int, int>
using namespace std;

// 최단경로를 저장할 배열
int d[maxV];
int d_s[maxV];          // Source : s
int d_h[maxV];          // Source : h
int d_g[maxV];          // Source : g
int visit[maxV];        // 방문 여부를 저장할 배열
vector<int> dest_list;  // 목적지 후보들을 저장하는 배열
vector<pii> list[maxV]; // Adjacency List
vector<int> result;
int MIN(int a, int b)
{
    if (a > b)
        return b;
    else
    {
        return a;
    }
}
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
// 기본적으로 maxheap이므로 구조체를 다시 정의해주어야 한다.
priority_queue<pii, vector<pii>, cmp> pq; // priority queue for Dijkstra

// Single Source s를 기준으로, 다익스트라 알고리즘 실행
/* 
1. Single Source
2. 최단거리를 저장할 배열
 */
void Dijkstra(int s);

int n = 0, m = 0, t = 0, s = 0, g = 0, h = 0, a = 0, b = 0, d_ = 0, d_gh = 0;

int main()
{
    // 테스트 케이스의 개수
    int TC = 0;
    scanf("%d", &TC);
    // cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        /* 
        n : vertext 개수
        m : edge 개수
        t : 후보 목적지 개수 */
        scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
        // cin >> n >> m >> t >> s >> g >> h;
        // vertex와 edge 개수에 대한 정보를 토대로 그래프를 구현한다
        // Adjacency List로 구현한다
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &d_);
            // cin >> a >> b >> d_;
            // a,b 사이에 가중치가 d인 간선을 만든다
            pii edge; //pii 객체 생성
            edge.first = b;
            edge.second = d_;
            list[a].push_back(edge);
            edge.first = a;
            edge.second = d_;
            list[b].push_back(edge);
            if (((a == g) && (b == h)) || ((a == h) && (b == g)))
                d_gh = d_;
        }

        // t개의 목적지 후보들을 입력받는다
        for (int i = 0; i < t; i++)
        {
            // dest : 개별 '목적지 후보'를 저장하는 배열
            int dest = 0;
            scanf("%d", &dest);
            // cin >> dest;
            dest_list.push_back(dest);
        }

        // s 기준 다익스트라
        for (int i = 0; i < maxV; i++)
        {
            d[i] = d_s[i] = d_h[i] = d_g[i] = INF;
            visit[i] = white;
        }
        Dijkstra(s);
        for (int i = 0; i < maxV; i++)
            d_s[i] = d[i];

        // h기준 다익스트라
        for (int i = 0; i < maxV; i++)
        {
            d[i] = INF;
            visit[i] = white;
        }
        Dijkstra(h);
        for (int i = 0; i < maxV; i++)
            d_h[i] = d[i];

        // g기준 다익스트라
        for (int i = 0; i < maxV; i++)
        {
            d[i] = INF;
            visit[i] = white;
        }
        Dijkstra(g);
        for (int i = 0; i < maxV; i++)
            d_g[i] = d[i];

        for (vector<int>::iterator iter = dest_list.begin(); iter != dest_list.end(); iter++)
        {
            int t = 0;
            t = *iter;
            // 만약 g-h 간선을 포함하는 최단경로가 존재한다면 (s-g-h-t)
            if ((d_s[g] + d_gh + d_h[t]) == d_s[t])
                result.push_back(t);
            else if (d_s[h] + d_gh + d_g[t] == d_s[t])
                result.push_back(t);
        }
        sort(result.begin(), result.end(), less<int>());
        // cout << "nmtsgh=" << n << " " << m << " " << t << " " << s << " " << g << " " << h << " "
        //      << ": ";
        for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
        {
            cout << *iter;
            cout << " ";
        }
        cout << endl;

        // 각종 전역변수들 초기화
        result.clear();
        dest_list.clear();
        for (int i = 0; i < maxV; i++)
            list[i].clear();
    }
}

void Dijkstra(int s)
{
    // initialize single source s
    d[s] = 0;
    // initialize priority queue
    while (!pq.empty())
    {
        pq.pop();
    }

    pq.push(make_pair(s, 0));
    while (!pq.empty())
    {
        // 우선순위 큐에서 하나를 뽑는다
        int u = 0, d_u = 0;
        u = pq.top().first;
        d_u = pq.top().second;
        pq.pop();

        // 방문 처리
        if (visit[u] == black)
            continue;

        // 인접 노드들의 경로 업데이트
        vector<pii>::iterator iter = list[u].begin();
        for (; iter != list[u].end(); iter++)
        {
            int v = 0, d_uv = 0;
            v = (*iter).first;
            d_uv = (*iter).second;

            // 이미 방문한 노드는 더 이상 최단거리를 업데이트할 필요가 없음
            if (visit[v] == black)
                continue;

            // 경로 업데이트
            d[v] = MIN(d[v], d[u] + d_uv);

            // 우선순위 큐에 삽입
            pq.push(make_pair(v, d[v]));
        }
        visit[u] = black;
    }
}