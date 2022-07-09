#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> vec;

int calc(int i, int j)
{
    char default_color = 'W';
    char other_color = 'B';
    int cnt_1 = 0, cnt_2 = 0;

    for (int k = 0; k < 8; k++)
    {
        for (int l = 0; l < 8; l++)
        {
            if (((k + l) % 2) == 0)
            {
                if (vec[i + k][j + l] != default_color)
                    cnt_1++;
            }
            else
            {
                if (vec[i + k][j + l] != other_color)
                    cnt_1++;
            }
        }
    }

    default_color = 'B';
    other_color = 'W';
    for (int k = 0; k < 8; k++)
    {
        for (int l = 0; l < 8; l++)
        {
            if (((k + l) % 2) == 0)
            {
                if (vec[i + k][j + l] != default_color)
                    cnt_2++;
            }
            else
            {
                if (vec[i + k][j + l] != other_color)
                    cnt_2++;
            }
        }
    }

    return min(cnt_1, cnt_2);
}

int main()
{

    int N = 0, M = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        vector<char> v;
        string cur_str = "";
        cin >> cur_str;
        for (int j = 0; j < cur_str.length(); j++)
        {
            v.push_back(cur_str[j]);
        }
        vec.push_back(v);
    }

    int min_num = 999999;

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            int num = calc(i, j);
            min_num = min(min_num, num);
        }
    }

    cout << min_num;
}