#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 100000;
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        float d = (float)i;
        // cout << d << " " << pow(2, d) << " " << d / pow(2,d) << endl;
        sum += d / pow(2, d);

    }
    cout << sum;
}