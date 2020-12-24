#include <bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &A)
{
    int l = A.size();
    int m = A[0];
    int n = A[0];
    int id = -1;
    bool check = false;

    for (int i = 1; i < l; i++)
    {
        if (!check)
        {
            if (A[i] > n)
            {
                id = i;
                m = n = A[i];
                check = true;
            }
        }
        else
        {
            if (A[i] > m)
            {
                n = A[i];
                continue;
            }
            else
            {
                id = -1;
                check = false;
            }
        }
    }
    // cout << id << endl;
    return (id == -1 || id == l - 1) ? 0 : 1;
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

    cout << perfectPeak(A) << endl;
}