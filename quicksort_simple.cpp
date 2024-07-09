#include <iostream>
#include <vector>

using namespace std;

// 탐색 이후
// low : 이전까지 pivot 이하임을 보장 -> pivot 초과를 가리킴
// high : 이후부터는 pivot 초과임을 보장 -> pivot이하를 가리킴
vector<int> sort(vector<int> vec)
{
    // 재귀의 끝
    if (vec.size() <= 1) return vec;

    int left = 0;
    int right = vec.size() -1;

    // 피봇을 고른다
    int pivot_idx = (left + right) / 2;

    vector<int> leftVec, rightVec;
    for (int i = left ; i <= right; i++)
    {
        if (i != pivot_idx)
        {
            if (vec[i] < vec[pivot_idx]) leftVec.push_back(vec[i]);
            else rightVec.push_back(vec[i]);
        }
    }
    vector<int> sortedleft = sort(leftVec);
    vector<int> sortedRight = sort(rightVec);
    vector<int> ans;
    
    for (auto& elem:sortedleft) ans.push_back(elem);
    ans.push_back(vec[pivot_idx]);
    for (auto& elem:sortedRight) ans.push_back(elem);

    return ans;

}

int main()
{
    vector<int> vec = {3,3,1,2,4,5};
    vector<int> ans = sort(vec);
    for (auto& i : ans)
        cout << i << endl;

}