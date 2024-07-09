#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    vector<bool> visit = vector<bool>(101, false);
    vector<Node *> newNodes = vector<Node *>(101, nullptr);

    void deepcopy(Node *node, Node *target)
    {
        assert(node->val == target->val);

        // 방문처리
        if (visit[node->val] == true)
            return;
        visit[node->val] = true;

        cout << node->val << endl;

        // 이웃 복사
        for (Node *neighbor : node->neighbors)
        {
            int val = neighbor->val;

            // 없다면 생성
            if (!newNodes[val])
                newNodes[val] = new Node(val);
            // 연결
            target->neighbors.push_back(newNodes[val]);
        }
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (visit[node->neighbors[i]->val] == false)
                deepcopy(node->neighbors[i], target->neighbors[i]);
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;

        queue<Node *> q;
        q.push(node);
        Node *cloneNode = new Node(node->val);

        deepcopy(node, cloneNode);

        return cloneNode;
    }
};

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution s;
    Node *clone = s.cloneGraph(node1);

    // Output adjacency list of the clone
    cout << "Clone adjacency list:" << endl;
    


    return 0;
}