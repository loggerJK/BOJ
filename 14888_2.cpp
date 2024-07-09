#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> oper(4, 0);
vector<int> datavec = {};
vector<char> stack = {};
int N;
int max_num = INT_MIN, min_num = INT_MAX;

int getNum()
{
    int result = datavec[0];
    for (int i = 1; i < N; i++)
    {
        if (stack[i - 1] == 0)
            result += datavec[i];
        if (stack[i - 1] == 1)
            result -= datavec[i];
        if (stack[i - 1] == 2)
            result *= datavec[i];
        if (stack[i - 1] == 3)
            result /= datavec[i];
    }
    return result;
}

void DFS(int a, int depth)
{
    // 방문할 수 없는 경우
    if (oper[a] <= 0)
        return;
    oper[a]--;
    stack.push_back(a);

    // 모두 방문한 경우
    if (depth == N - 1)
    {
        int result = getNum(); // todo
        max_num = max(max_num, result);
        min_num = min(min_num, result);

        oper[a]++;
        stack.pop_back();
        return;
    }

    for (int i = 0; i < 4; i++)
        DFS(i, depth + 1);

    oper[a]++;
    stack.pop_back();
}

int main()
{
    cin >> N;

    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        datavec.push_back(input);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> input;
        oper[i] = input;
    }

    for (int i = 0; i < 4; i++)
        DFS(i, 1);

    cout << max_num << endl << min_num << endl;
}