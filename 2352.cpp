// Greedy

#include <iostream>
#include <stdio.h>
#define MAX 40004

using namespace std;

// struct node
// {
//     int dest;
// };

int arr[MAX]; // 연결되어있는 노드 정보
int d[MAX];   //
int N = 0;
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        d[i] = 0;
    }
    // 그리디 알고리즘
    int lower_bound = 0;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] > lower_bound && i >= arr[i])
        {
            d[i] = d[i - 1] + 1;
            lower_bound = arr[i];
        }
        else
            d[i] = d[i - 1];
    }

    //
    cout << d[N];
}
