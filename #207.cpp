#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    queue<int> q;
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> edge;
        int indegrees[2001];
        bool visit[2001];
        int N = prerequisites.size();
        for (int i = 0; i < 2001; i++)
        {
            vector<int> tmp;
            edge.push_back(tmp);
            indegrees[i] = 0;
            visit[i] = false;
        }

        for (auto &vec : prerequisites)
        {
            edge[vec[0]].push_back(vec[1]);
            indegrees[vec[1]]++;
        }

        // 큐에 푸쉬
        for (int i = 0; i < N; i++)
            if (indegrees[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int idx = q.front();
            q.pop();

            // 방문처리
            if (visit[idx] == true)
                continue;
            visit[idx] = true;

            // 인접노드들의 indegree를 낮춘다
            // 인접노드가 방문 가능하면 큐에 푸시

            for (auto &node : edge[idx])
            {
                indegrees[node]--;
                if ((visit[node] == false) && (indegrees[node] == 0))
                    q.push(node);
            }
        }

        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (visit[i] == false)
                return false;

        cout << visit[0] << endl << visit[1] << endl;

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec = {{1, 0}};
    cout << s.canFinish(2, vec);
}