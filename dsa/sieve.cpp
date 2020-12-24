#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int A)
{
    vector<int> rs;
    if (A == 1)
        return rs;
    double sq = sqrt(A);
    int ch[A + 1];
    for (int i = 0; i <= A; i++)
    {
        ch[i] = 1;
    }
    ch[0] = 0;
    ch[1] = 0;

    for (int i = 2; i <= sq; i++)
    {
        if (ch[i] == 1)
        {
            int j = i + i;
            while (j <= A)
            {
                ch[j] = 0;
                j = j + i;
            }
        }
    }
    for (int i = 0; i <= A; i++)
    {
        if (ch[i] == 1)
            rs.push_back(i);
    }
    return rs;
}
int main()
{
    int a;
    cin >> a;

    vector<int> f = sieve(a);
    for (int i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
}