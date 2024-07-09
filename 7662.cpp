#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
#define ll long long

int main() {

    ll N;
    cin >> N;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll tc = 0; tc < N; tc++)
    {
        ll K;
        cin >> K;
        vector<string> operations; 
        for (ll i = 0; i < K; i++)
        {
            string str, str2;
            cin >> str >> str2;
            operations.push_back(str + " " + str2);
        }
        vector<ll> answer;
        
        multiset<ll> m;
        
        for (ll i = 0; i < operations.size(); i++)
        {
            string str = operations[i];
            ll num = stoi(str.substr(2));
            
            if (str.substr(0,1) == "I")
                m.insert(num);
            else
            {
                if (m.size() >= 1)
                {
                    if (num > 0)
                    {
                        auto iter = m.end();
                        iter--;
                        m.erase(iter);
                    }
                    else
                    {
                        auto iter = m.begin();
                        m.erase(iter);
                    }
                }
            }
        }
        
        if (!m.empty())
        {
            
            auto iter = m.begin();
            ll min = *iter;
            iter = m.end();
            iter--;
            ll max = *iter;
            answer.push_back(max);
            answer.push_back(min);
            cout << max << " " << min << endl;
        }
        else
        {
            answer.push_back(0);
            answer.push_back(0); 
            cout << "EMPTY" << endl;
        }
        
    }

}