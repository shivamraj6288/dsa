#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{
    int n = A.size();
    stack<int> a;
    stack<int> b;
    for (int i = 0; i < n; i++)
    {
        a.push(A[i]);
        b.push(A[n - 1 - i]);
    }
    vector<int> rs(n);
    int i = n - 1;
    while (a.size() + b.size() != n)
    {
        if (a.top() >= abs(b.top()))
        {
            rs[i] = a.top() * a.top();
            i--;
            a.pop();
        }
        else
        {
            rs[i] = b.top() * b.top();
            i--;
            b.pop();
        }
    }
    return rs;
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

    A = solve(A);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
