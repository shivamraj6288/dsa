#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();
    int suff[n][2];

    int nspecial = 0;

    if (n == 1)
    {
        return 1;
    }

    if ((n - 1) % 2 == 0)
    {
        suff[n - 1][0] = A[n - 1];
        suff[n - 1][1] = 0;
    }
    else
    {
        suff[n - 1][0] = 0;
        suff[n - 1][1] = A[n - 1];
    }

    for (int i = n - 2; i >= 0; i = i - 1)
    {
        if (i % 2 == 0)
        {
            suff[i][0] = suff[i + 1][0] + A[i];
            suff[i][1] = suff[i + 1][1];
        }
        else
        {
            suff[i][0] = suff[i + 1][0];
            suff[i][1] = suff[i + 1][1] + A[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int d1 = suff[0][0] - suff[i][0];
        int d2 = suff[1][1] - suff[i][1];

        if (i % 2 == 0)
        {
            d2 += (suff[i][0] - A[i]);
            d1 += suff[i][1];
        }
        else
        {
            d2 += suff[i][0];
            d1 += (suff[i][1] - A[i]);
        }
        if (d1 == d2)
        {
            nspecial++;
        }
    }
    return nspecial;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    cout << solve(A) << endl;
}