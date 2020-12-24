#include <bits/stdc++.h>
using namespace std;

int isPrime(int A)
{
    if (A == 1)
        return 0;
    double sq = sqrt(A);
    for (int i = 2; i <= sq; i++)
    {
        if (i == sq)
        {
            return 0;
        }
        if (A % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a;
    cin >> a;

    cout << isPrime(a);
}