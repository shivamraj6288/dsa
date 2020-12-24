#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
    int m1, m2, m3, m4;
    m1 = min(8 - a, 8 - b);
    m2 = min(a - 1, 8 - b);
    m3 = min(a - 1, b - 1);
    m4 = min(8 - a, b - 1);
    return m1 + m2 + m3 + m4;
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << solve(a, b);
    cout << endl;
}