#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int L = 0, C = 0;

vector<char> characters;
vector<int> index_vec;
vector<char> vowels;
/*  
char_map[a]
-Value Explanation-
1 : 모음
0 : 자음
*/
bool is_vowel(char &a)
{
    for (int i = 0; i < 5; i++)
        if (vowels[i] == a)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //init
    cin >> L >> C;

    vowels.push_back('a');
    vowels.push_back('e');
    vowels.push_back('i');
    vowels.push_back('o');
    vowels.push_back('u');

    for (int i = 0; i < L; i++)
        index_vec.push_back(1);
    for (int i = L; i < C; i++)
        index_vec.push_back(0);

    // get input
    for (int c = 0; c < C; c++)
    {
        char a = 0;
        cin >> a;
        characters.push_back(a);
    }

    sort(characters.begin(), characters.end(), less<char>());

    do
    {
        string str;
        str.clear();
        int cnt_vowel = 0, cnt_consonant = 0;
        for (int idx = 0; idx < index_vec.size(); idx++)
        {
            // combinations
            if (index_vec[idx] == 1)
            {
                // check if vowel or consonant
                if (is_vowel(characters[idx]))
                    cnt_vowel++;
                else
                    cnt_consonant++;

                // make string
                str.push_back(characters[idx]);
            }
        }
        if ((cnt_vowel >= 1) && (cnt_consonant >= 2))
            cout << str << "\n";
    } while (prev_permutation(index_vec.begin(), index_vec.end()));
}