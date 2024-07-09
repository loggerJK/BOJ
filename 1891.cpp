#include <iostream>
#include <tuple>
#include <string>
#include <cmath>
#define ll long long
#define tii tuple<ll,ll>
using namespace std;
ll d, dr, dc;
string num;
// depth : n - 1
tii proj(string num, ll n, ll depth, ll r, ll c)
{
    if (depth == 0)
        return make_tuple(r,c);

    char status = num[0] - '0';
    // cout << "status: " << status << endl;
    // cout << "r: " << r << " c: " << c << endl;
    switch (status)
    {
    case 2:
        return proj(num.substr(1), n, depth - 1, r, c);
        break;
    case 1:
        return proj(num.substr(1), n, depth - 1, r, c + pow(2, depth - 1));
        break;
    case 3:
        return proj(num.substr(1), n, depth - 1, r + pow(2, depth - 1), c);
        break;
    case 4:
        return proj(num.substr(1), n, depth - 1, r + pow(2, depth - 1), c + pow(2, depth - 1));
        break;
    default:
        break;
    }
}

string unproj(ll n, ll r, ll c)
{
    if ((r < 0) || (c < 0) || (r >= pow(2, n)) || (c >= pow(2, n)))
        return "-1";

    // 예외 처리
    if (n == 1)
    {
        if ((r==0) && (c == 0)) return "2";
        else if ((r == 0) && (c == 1)) return "1";
        else if ((r == 1) && (c == 0)) return "3";
        else return "4";
    }

    if (r < pow(2, n - 1) && c < pow(2, n - 1))
    {
        // case 0, 2사분면
        return "2"  + unproj(n-1, r, c);
    }
    else if (r < pow(2, n - 1) && c >= pow(2, n - 1))
    {
        // case 1, 1사분면
        return "1"  + unproj(n-1, r, c - pow(2, n - 1));
    }
    else if (r >= pow(2, n - 1) && c < pow(2, n - 1))
    {
        // case 2, 3사분면
        return "3"  + unproj(n - 1, r - pow(2, n - 1), c);
    }
    else if (r >= pow(2, n - 1) && c >= pow(2, n - 1))
    {
        // case 3, 4사분면
        return "4"  + unproj(n - 1, r - pow(2, n - 1), c - pow(2, n - 1));
    }
}

int main()
{
    cin >> d >> num >> dc >> dr;

    ll r, c;
    // cout << "num : " << num << endl;
    // cout << "num[0] : " << num[0] << endl;
    tii result = proj(num, d, d, 0, 0);
    r = get<0>(result);
    c = get<1>(result);

    // cout << r << endl << c << endl;

    string answer = unproj(d, r - dr,c + dc);

    cout << answer;

}