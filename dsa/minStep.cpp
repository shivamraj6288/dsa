#include <bits/stdc++.h>
using namespace std;
int coverPoints(vector<int> &A, vector<int> &B)
{
    int steps = 0;
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        int dmax = max(abs(A[i] - A[i - 1]), abs(B[i] - B[i - 1]));

        if (dmax <= 1)
        {
            steps += dmax;
            // cout << "enter\n";
            continue;
        }
        int d1 = min(abs(A[i] - A[i - 1]), abs(B[i] - B[i - 1]));
        steps += d1;
        steps += dmax - d1;
    }
    return steps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        B[i] = a;
    }
    cout << coverPoints(A, B) << endl;
    return 0;
}