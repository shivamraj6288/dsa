#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    int n = A.size();
    int b = B - 1;
    int nb = 0;
    int i = min(b, n - 1);
    while (i < n)
    {
        if (A[i] == 1)
        {
            nb++;
            if (i + b >= n - 1)
                return nb;
            i = i + b + B;
            if (i > n - 1)
            {
                i = i - b - B;
                for (int j = n - 1; j > i; j--)
                {
                    if (A[j] == 1 && j + b >= n - 1)
                    {
                        nb++;
                        return nb;
                    }
                    if (j == i + 1)
                    {
                        return -1;
                    }
                }
            }
            continue;
        }

        int j = i - b - B;
        // cout << j << endl;
        bool ch = false;
        while (i > j)
        {
            if (A[i] == 1)
            {
                nb++;
                if (i + b >= n - 1)
                    return nb;
                i = i + b + B;
                if (i > n - 1)
                {
                    i = i - b - B;
                    for (int j = n - 1; j > i; j--)
                    {
                        if (A[j] == 1 && j + b >= n - 1)
                        {
                            nb++;
                            return nb;
                        }
                        if (j == i + 1)
                        {
                            return -1;
                        }
                    }
                }
                ch = true;
                break;
            }
            i--;
        }
        if (!ch)
            return -1;
    }

    return nb;
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
    int B;
    cin >> B;
    cout << solve(A, B) << endl;
}
