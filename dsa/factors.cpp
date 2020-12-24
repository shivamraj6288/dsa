#include <bits/stdc++.h>
using namespace std;

vector<int> factor(int A)
{
    vector<int> f1;
    vector<int> f2;
    double n = sqrt(A);
    for (int i = 1; i <= n; i++)
    {
        if (A % i == 0)
        {
            if (i == n)
            {
                f1.push_back(n);
                continue;
            }
            f1.push_back(i);
            f2.push_back(A / i);
        }
    }
    // if (A % n == 0)
    // {
    //     f1.push_back((int)n);
    // }
    // for (int i = 0; i < f1.size(); i++)
    // {
    //     cout << f1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < f2.size(); i++)
    // {
    //     cout << f2[i] << " ";
    // }

    for (int i = 0; i < f2.size() / 2; i++)
    {
        int temp = f2[i];
        f2[i] = f2[f2.size() - 1 - i];
        f2[f2.size() - 1 - i] = temp;
    }
    f1.insert(f1.end(), f2.begin(), f2.end());
    return f1;
}
int main()
{
    int a;
    cin >> a;
    vector<int> f = factor(a);
    for (int i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
}