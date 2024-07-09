#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10, m = 10;
    // vector<vector<int>> tmp = vector<vector<int>> (10, vector<int> (10, 1));
    vector<vector<int>> tmp(n, vector<int>(m, 0));
    vector<vector<int>> edge(10, vector<int>{});

    for (auto row : tmp)
    {
        for (auto elem : row)
            cout << elem;;
        cout << endl;
    }
}