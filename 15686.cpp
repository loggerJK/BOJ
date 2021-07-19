#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define INF 9999999
using namespace std;

// global variables
int N = 0, M = 0;

vector<vector<int>> map;
vector<pii> coordinate_home;
vector<pii> coordinate_chicken;
vector<int> min_chicken_distance_list;

int getChickenDistance(pii home, pii chicken)
{
    return abs(home.first - chicken.first) + abs(home.second - chicken.second);
}

int MIN(int &a, int &b)
{
    if (a > b)
        return b;
    else
        return a;
}

int main()
{
    // get input
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        vector<int> row;
        map.push_back(row);
        for (int j = 0; j < N; j++)
        {
            int info = 0;
            cin >> info;
            if (info == 1)
            {
                // 집인 경우
                coordinate_home.push_back(make_pair(i, j));
            }
            else if (info == 2)
            {
                // 치킨집인 경우
                coordinate_chicken.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> temp_vector;
    for (int i = 0; i < M; i++)
        temp_vector.push_back(1);
    for (int i = M; i < coordinate_chicken.size(); i++)
        temp_vector.push_back(0);

    sort(temp_vector.begin(), temp_vector.end());

    int city_chicken_distance = INF;

    do
    {
        int tmp = 0;

        for (vector<pii>::iterator iter = coordinate_home.begin(); iter != coordinate_home.end(); iter++)
        {
            // 집 좌표를 불러온다
            pii coor_home;
            coor_home = (*iter);
            int minimum = INF;

            /* 
            M개의 치킨집 중에서
            가장 작은 치킨 거리를 선택한다
             */
            for (int idx = 0; idx < coordinate_chicken.size(); idx++)
            {
                if (temp_vector[idx] == 1)
                {
                    pii coor_chicken;
                    coor_chicken = coordinate_chicken[idx];
                    int chicken_distance = 0;
                    chicken_distance = getChickenDistance(coor_home, coor_chicken);
                    minimum = MIN(minimum, chicken_distance);
                }
            }
            tmp += minimum;
        }

        city_chicken_distance = MIN(city_chicken_distance, tmp);

    } while (next_permutation(temp_vector.begin(), temp_vector.end()));

    cout << city_chicken_distance;
}
