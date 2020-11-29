// LIS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001

using namespace std;

vector<int> input;
vector<int> ing_;
vector<int> final_;
int N = 0;

void PUSH(int a);

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n = 0;
        cin >> n;
        input.push_back(n);
    }

    ing_.push_back(-(INF));

    for (int i = 0; i < N; i++)
    {
        int n = 0;
        n = input[i];

        PUSH(n);
    }

    cout << ing_.size() - 1;
}

void PUSH(int a)
{
    // 사이즈 체크
    int prev_size = final_.size();

    // ing_의 lowerbound를 찾아서 삽입한다.
    vector<int>::iterator lowest = lower_bound(ing_.begin(), ing_.end(), a);

    if (lowest == ing_.end())
    {
        // 제일 큰 값이 들어오는 경우이다.
        ing_.push_back(a);
    }
    else
    {
        int index = 0;
        index = lowest - ing_.begin();
        ing_[index] = a;
    }
}