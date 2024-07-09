#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector< vector<int> > edge;
vector<int> parent;

bool comp (vector<int> a, vector<int> b)
{
    return a.back() < b.back();
}

int find(int i)
{
    if (i == parent[i]) return i;
    else return parent[i] = find(parent[i]);
}

void merge(int i, int j)
{
    int pi , pj;
    pi = find(i);
    pj = find(j);

    // 순서 맞출 것!!
    if (pi < pj) parent[pi] = pj;
    else parent[pj] = pi;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a,b,c});
    }   

    sort(edge.begin(), edge.end(), comp);

    vector<vector<int>> finalEdge;
    
    // range : 1 ~ N
    for (int i = 0; i <= N; i++)
        parent.push_back(i);

    int idx = 0;
    for (int cnt = 0; cnt < N-1; idx++)
    {
        vector<int> curedge = edge[idx];

        int i, j, k;
        i = curedge[0];
        j = curedge[1];
        k = curedge[2];

        int pi, pj;
        pi = find(i);
        pj = find(j);
        if (pi != pj)
        {
            merge(i,j);
            finalEdge.push_back(curedge);
            cnt++;
        }
    }

    int sum = 0;
    for (auto edge : finalEdge)
        sum += edge[2];

    cout << sum - (finalEdge.back())[2];



    



}