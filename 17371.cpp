#include <stdio.h>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
vector<pair<long long, long long>> vec;
map<pair<long long, long long>, pair<long long, long long>> Map;
pair<long long, long long> minPair1;
pair<long long, long long> minPair2;
long long minDistance = 10000000000;

int main()
{
    int N = 0; // number of all vertices
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        long long A = 0, B = 0;
        scanf("%lld %lld", &A, &B);
        Map.insert(pair<pair<long long, long long>, pair<long long, long long>>(pair<long long, long long>(A, B), pair<long long, long long>(A, B)));
    }
    map<pair<long long, long long>, pair<long long, long long>>::iterator iter = Map.begin();
    for (; iter != Map.end(); iter++)
    {
        map<pair<long long, long long>, pair<long long, long long>>::iterator iter2 = Map.begin();
        for (; iter2 != Map.end(); iter2++)
        {
            if (iter == iter2)
                continue;
            // 거리를 비교한다. pair에 저장된 정점보다 거리가 멀다면 업데이트
            long long Ax = 0, Ay = 0, Ax2 = 0, Ay2 = 0, Bx = 0, By = 0;
            Ax = (*iter).first.first;
            Ay = (*iter).first.second;
            Ax2 = (*iter).second.first;
            Ay2 = (*iter).second.second;
            Bx = (*iter2).first.first;
            By = (*iter2).first.second;
            long long prevdistance = pow(Ax - Ax2, 2) + pow(Ay - Ay2, 2);
            long long distance = pow(Ax - Bx, 2) + pow(Ay - By, 2);
            if (prevdistance < distance) // 거리가 더 먼 정점이 발견된다면
            {
                (*iter).second = (*iter2).first;
                // 최솟값 정보 업데이트
            }
        }
        long long Ax = 0, Ay = 0, Ax2 = 0, Ay2 = 0, Bx = 0, By = 0;
        Ax = (*iter).first.first;
        Ay = (*iter).first.second;
        Ax2 = (*iter).second.first;
        Ay2 = (*iter).second.second;
        long long distance = pow(Ax - Ax2, 2) + pow(Ay - Ay2, 2);
        // 최단거리 업데이트
        if (distance < minDistance)
        {
            minDistance = distance;
            minPair1 = (*iter).first;
            minPair2 = (*iter).second;
        }
    }

    long double Ax = 0, Ay = 0, Bx = 0, By = 0;
    Ax = minPair1.first;
    Ay = minPair1.second;
    Bx = minPair2.first;
    By = minPair2.second;
    // Ax = (Ax + (Bx - Ax) / 10.0);
    // Ay = (Ay + (By - Ay) / 10.0);

    printf("%Lf %Lf", Ax, Ay);
}