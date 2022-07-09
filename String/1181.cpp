#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

vector<string> vec;
set<string> s;

bool compare(const string &s1, const string &s2)
{
    if (s1.length() < s2.length())
    {
        return true;
    }
    else if (s1.length() > s2.length())
        return false;
    else
    {
        if (s1 < s2)
            return true;
        else
            return false;
    }
}

int main()
{
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string cur_str = "";
        cin >> cur_str;
        s.insert(cur_str);
    }

    for (auto i : s)
    {
        vec.push_back(i);
    }

    sort(vec.begin(), vec.end(), compare);

    for (auto s : vec)
        cout << s << endl;
}
