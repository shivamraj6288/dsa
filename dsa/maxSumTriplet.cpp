#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A)
{
    
    int n = A.size();
    int suff[n];
    suff[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] >= A[suff[i + 1]])
            suff[i] = i;
        else
            suff[i] = suff[i + 1];
    }
    int sum = 0;
    set<int> s;
    set<int>::iterator it;
    s.insert(A[0]);
    for (int i = 1; i < n - 1; i++)
    {
        s.insert(A[i]);
        it = s.lower_bound(A[i]);
        if (it == s.begin())
            continue;
        if (suff[i] == i)
            continue;

        int tsum = *(--it) + A[i] + A[suff[i]];
        if (tsum > sum)
            sum = tsum;
    }
    return sum;
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