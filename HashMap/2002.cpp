#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int N = 0;

unordered_map<string, int> umap;
unordered_map<string, int> umap2;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str = "";
        cin >> str;
        umap[str] = i;
    }

    for (int i = 0; i < N; i++)
    {
        string str = "";
        cin >> str;
        umap2[str] = i;
    }

        int cnt = 0;
    for (auto iter2 : umap2)
    {
        string cur_str;
        int cur_rank, cur_rank_2;
        cur_str = iter2.first;
        cur_rank_2 = iter2.second;
        cur_rank = umap[cur_str];
        for (auto iter : umap)
        {
            string prev_str = iter.first;
            int prev_rank = iter.second;
            int prev_rank_2 = umap2[prev_str];
            if (prev_rank < cur_rank && cur_rank_2 < prev_rank_2)
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
}