#include <iostream>
#include <vector>

using namespace std;

// 탐색 이후
// low : 이전까지 pivot 이하임을 보장 -> pivot 초과를 가리킴
// high : 이후부터는 pivot 초과임을 보장 -> pivot이하를 가리킴
void sort(vector<int>& vec, int left, int right)
{
    // 원소의 개수가 하나이면 바로 반환
    if (vec.size() == 1) return;
    if (left >= right) return;

    int pivot = vec[left];
    int low = left + 1;
    int high = right;

    while (low <= high)
    {
        // low와 high를 탐색
        while (vec[low] < pivot && low <= right)
            low++;
        while (vec[high] > pivot && left <= high)
            high--;

        // swap    
        if (low < high)
        {
            cout << "SWAP: " << vec[low] << " " << vec[high] << endl; 
            int temp = vec[high];
            vec[high] = vec[low];
            vec[low] = temp;
        }
    }

    // 끝나고 나면 left, high swap
    int temp = vec[high];
    vec[high] = pivot;
    vec[left] = temp;

    sort(vec, left, high-1);
    sort(vec, high+1, right);

}

int main()
{
    vector<int> vec = {3,3,1,2,4,5};
    sort(vec, 0, vec.size() - 1) ;
    for (auto& i : vec)
        cout << i << endl;

}