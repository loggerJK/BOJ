#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int M = 0, N = 0;
vector<int> vec;

int main()
{
    cin >> M >> N;

    /* 
    2~N까지 벡터에 담는다

    2~ N까지 '배수 삭제'를 시행한다

    M~N까지 count
     */

    for (int i = 2; i <= N; i++)
        vec.push_back(i);

    vector<int>::iterator iter = vec.begin();
    for (; iter != vec.end(); iter++)
    {
        int a = *iter;
        if (a == -1)
            continue;

        // a 가 루트N보다 크다면 더 이상 배수 삭제할 필요가 없다
        if (a > sqrt(N))
            break;

        for (vector<int>::iterator iter2 = iter + 1; iter2 < vec.end(); iter2++)
        {
            int b = *iter2;
            // 이미 지워진 수라면 건너뛴다
            if (b == -1)
                continue;
            // b가 a의 배수라면 b를 벡터에서 삭제한다
            if (b % a == 0)
                vec[iter2 - vec.begin()] = -1;
        }
    }

    // int cnt = 0;

    // iter = vec.end() - 1;
    // for (; iter >= vec.begin(); iter--)
    // {
    //     if (*iter >= M)
    //         ++cnt;
    //     else
    //     {
    //         break;
    //     }
    // }

    // cout << cnt;

    for (iter = vec.begin(); iter < vec.end(); iter++)
    {
        if (*iter >= M)
            cout << *iter << '\n';
        // printf("%d\n", *iter);
    }

    // for (iter = vec.end() - 1; iter >= vec.begin(); iter--)
    // {
    //     if (*iter == -1)
    //         continue;
    //     if (*iter < M)
    //         break;
    //     else
    //         cout << *iter << endl;
    // }
}