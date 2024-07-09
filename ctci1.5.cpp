#include <iostream>
#include <string>

using namespace std;

bool sol(string a, string b)
{
    string smaller, bigger;

    if (a.length() < b.length())
    {
        smaller = a;
        bigger = b;
    }
    else if (a.length() > b.length())
    {
        smaller = b;
        bigger = a;
    } 
    else
    {
        // 길이가 동일한 경우
        // 교체 케이스에 대해서 검사한다
        int cnt = 0, i = 0, j = 0;
        while (i < a.length() && j < b.length())
            {
                // 문자열이 다른 것이 한번인 경우만 허용한다
                if (a[i] != b[j])
                {
                    if (cnt == 0) cnt++;
                    else return false;
                }
                i++;
                j++;
            }
        
        return true;
    }

    // 길이가 서로 다른 경우
    int cnt = 0, i = 0, j = 0;
    while (i < smaller.length() && j < bigger.length())
    {
        // 문자열이 다른 것이 한번인 경우만 허용한다
        if (smaller[i] != smaller[j])
        {
            if (cnt == 0)
            {
                // longer를 한번 더 이동
                j++;
            }
            else
                return false;
        }
        else
        {
            i++;
            j++;
        }
    }

    return true;
}

int main()
{
    cout << sol("pale", "ple") << endl; // 1
    cout << sol("pales", "pale") << endl; // 1
    cout << sol("pale", "bale") << endl; // 1
    cout << sol("pale", "bake") << endl; // 0

}