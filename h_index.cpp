#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), comp);

    for (int i = 0; i < citations.size(); i++)
    {
        int cur_idx = citations[i];
        int num = i + 1;
        if (cur_idx >= num)
        {
            answer = num;
        }
        else
        {
            break;
        }
    }
    return answer;
}

void print(vector<int> citations, int answer) {
    int t = solution(citations);
    if (t == answer)
        cout << "정답" << endl;
    else
        cout << t << "틀림" << endl;
}
 
int main()
{   vector<int> citations = { 3, 0, 6, 1, 5 };
    print(citations, 3);
    print({ 7 },1);
    print({ 1545, 2, 999, 790, 540, 10, 22 }, 6);
    print({22, 47}, 2);
    print({2, 7, 5}, 2);
    print({4, 3, 3, 3, 3}, 3);
    print({10, 50, 100}, 3);
    print({1, 7, 0, 1, 6, 4}, 3);
    print({0}, 0);
    return 0;
}