#include <iostream>
#include <string>

using namespace std;



int main()
{
    string s = "aabcccccaaa";
    string answer = "";

    // 시작점
    // 카운터 변수
    int cnt = 1;
    int i = 0;
    int j = 1;
    while (j < s.length()) 
        {
            // 문자가 다른 경우
            if (s[i] != s[j])
            {
                // 답 갱신
                answer += (s[i]);
                answer += to_string(cnt);
                i = j;
                j = i+1;
                cnt = 1;
                continue;
            }
            // 문자가 같은 경우
            else{
                cnt++;
                j++;
            }
            cout << "i : " << i << " j : " << j << endl;
        }

    // 마지막에도 추가
    answer += (s[i]);
    answer += to_string(cnt);

    cout << answer;
}