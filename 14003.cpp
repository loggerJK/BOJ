// LIS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define INF 1000000005

using namespace std;

vector<int> Input;
vector<int> Idx;
vector<int> temp;
stack<int> Stack;
void Process(int n, int i);

int N = 0;

int main()
{
    cin >> N;

    temp.push_back(-(INF));
    for (int i = 0; i < N; i++)
    {
        int n = 0;
        cin >> n;
        Input.push_back(n);
    }

    for (int i = 0; i < N; i++)
    {
        int n = Input[i];
        Process(n, i);
    }

    int max = temp.size() - 1;
    vector<int>::iterator iter = lower_bound(Input.begin(), Input.end(), max);
    // iter가 가리키는 곳부터 역순출력을 진행한다.
    int idx = Idx.end() - Idx.begin() - 1;
    for (; idx >= 0; idx--)
    {
        if (Idx[idx] == max)
        {
            Stack.push(Input[idx]); // 인덱스를 스택에 저장한다
            --max;
        }
        else
        {
            continue;
        }
    }
    cout << temp.size() - 1 << endl;
    while (!Stack.empty())
    {
        int pop = 0;
        pop = Stack.top();
        Stack.pop();
        cout << pop << ' ';
    }
}

void Process(int n, int i)
{
    /* 
    1. temp에 적절히 넣을 위치를 찾는다.
    2. temp에 넣어준다.
    3. idx에 위치를 기록한다.
     */

    vector<int>::iterator iter = lower_bound(temp.begin(), temp.end(), n);

    int index = iter - temp.begin();
    Idx.push_back(index);
    if (iter == temp.end())
    {
        temp.push_back(n);
    }
    else
    {
        temp[index] = n;
    }
}