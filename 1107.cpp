#include <iostream>
#include <vector>
using namespace std;

int N = 0, M = 0;
vector<int> brokenBnt;

int MIN(int a, int b);
bool check(int a);

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int n = 0;
        cin >> n;
        brokenBnt.push_back(n);
    }

    int upper = -1, lower = -1;

    if (N == 100)
    {
        cout << 0;
        return 0;
    }

    // upperbound 검사, - 버튼이 활성화되어있을 경우;
    for (int i = N; i <= 1000001; i++)
    {
        if (check(i))
        {
            upper = i;
            break;
        }
        else
            continue;
    }
    // upper의 자릿수를 검사한다
    int temp = upper;
    int upper_cnt = 0;
    if (temp == 0)
        upper_cnt = 1;
    while (temp != 0)
    {
        temp /= 10;
        ++upper_cnt;
    }

    // lowerbound 검사, + 버튼이 활성화되어있을 경우;
    for (int i = N; i >= 0; i--)
    {
        if (check(i))
        {
            lower = i;
            break;
        }
        else
            continue;
    }
    temp = lower;
    int lower_cnt = 0;
    if (temp == 0)
        lower_cnt = 1;
    while (temp != 0)
    {
        temp /= 10;
        ++lower_cnt;
    }
    // 바로 입력 가능한 경우
    if (N == upper)
    {
        cout << MIN(abs(N - 100), upper_cnt);
    }
    else
    {
        if (upper != -1 && lower != -1)
            cout << MIN(abs(N - 100), MIN(upper - N + upper_cnt, N - lower + lower_cnt));
        else if (upper == -1 && lower == -1)
            cout << abs(N - 100);
        else if (upper == -1)
            cout << MIN(abs(N - 100), N - lower + lower_cnt);
        else if (lower == -1)
            cout << MIN(abs(N - 100), upper - N + upper_cnt);
    }
}
int MIN(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
bool check(int a)
{
    vector<int> num;
    // 자릿수별로 벡터에 삽입한다
    if (a == 0)
        num.push_back(a);
    while (a != 0)
    {

        int b = 0;
        b = a % 10;
        num.push_back(b);
        a /= 10;
    }

    // brokenBnt랑 중복되는 값이 있는지 검사한다
    for (int i = 0; i < M; i++)
    {
        int bnt = brokenBnt[i];
        for (int j = 0; j < num.size(); j++)
            if (bnt == num[j])
                return false;
    }

    // 중복되는 값이 없다면 true를 리턴
    return true;
}