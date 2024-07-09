#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> vec;

void recursionSearch(int start, int end)
{
    // 인덱싱을 이용한 종료 조건
    int size = 0;
    size = (start - end) + 1;
    if (size <= 0)
        return;
    // 루트만 존재하는 경우
    if (size == 1)
    {
        assert(start == end);
        cout << vec[start] << '\n';
    }
    if (size > 2)
    {
        // 트리의 루트와 나머지를 구분한다
        int leftRootidx = -1;
        int rightRootidx = -1;
        for (int i = start; i <= end; i++)
        {
            if (vec[i] < vec[start] && leftRootidx == -1)
            {
                leftRootidx = i;
            }
            if (vec[i] > vec[start] && rightRootidx == -1)
            {
                rightRootidx = i;
            }
        }
        // 왼쪽 트리를 대상으로 recursionSearch()
        if (leftRootidx != -1)
        {
            // 둘 다 존재하는 경우
            if (rightRootidx != -1)
            {
                
            }
            // 왼쪽 트리만 존재하는 경우
        }
        else 
        {
            if(rightRootidx != -1)
            {
                // 오른쪽 트리만 존재하는 경우
            }
        }

        // 루트 값을 출력
    }
}
int main()
{
    int x = 0;
    while (cin >> x)
    {
        vec.push_back(x);
    }

    recursionSearch(0, vec.size() - 1);
}