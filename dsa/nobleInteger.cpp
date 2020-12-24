#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();

    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
    {
        if (i == n - 1)
        {
            if (A[i] == 0)
                return 1;
            return -1;
        }
        if (A[i] == A[i + 1])
            continue;
        else
        {
            if (A[i] == n - 1 - i)
            {
                return 1;
            }
        }
    }
    return -1;
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
