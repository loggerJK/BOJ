#include <iostream>
#include <string>
#include <map>

using namespace std;

// 선언
int TC = 0, F = 0;
map<string, string> parent;
map<string, int> size_net_map;

int merge(string a, string b);
// return the size of network
string find_root(string a);
// return root node
void init_friend(string a);

// 구현
int merge(string a, string b)
{
    string root_a = find_root(a);
    string root_b = find_root(b);
    // 같은 집합이라면 합치지 않는다
    if (root_a.compare(root_b) == 0)
        return size_net_map[root_a];
    else
    {
        // 다른 집합이라면 합친다 b -> a
        parent[root_b] = root_a;
        // 집합의 개수 조절
        size_net_map[root_a] += size_net_map[root_b];
        size_net_map[root_b] = 1;
        return size_net_map[root_a];
    }
}

string find_root(string a)
{
    if (parent[a].compare(a) == 0)
        return a;
    else
    {
        // path compression
        parent[a] = find_root(parent[a]);
        return parent[a];
    }
}

void init_friend(string a)
{
    // 이미 있던 친구인지 체크하고 없다면 새로 정보를 입력
    map<string, string>::iterator iter;
    iter = parent.find(a);
    if (iter != parent.end())
    {
        // 만약 찾는 friend가 존재한다면 그대로 종료
        return;
    }
    else
    {
        parent.insert(pair<string, string>(a, a));
        size_net_map.insert(make_pair(a, 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        // init global variable
        parent.clear();
        size_net_map.clear();

        cin >> F;
        for (int f = 0; f < F; f++)
        {

            string s1 = "", s2 = "";
            cin >> s1 >> s2;

            // 이미 있던 친구인지 체크하고 없다면 새로 정보를 입력
            init_friend(s1);
            init_friend(s2);

            int cur_net_size = 0;
            cur_net_size = merge(s1, s2);

            cout << cur_net_size;
            cout << "\n";
        }
    }
}