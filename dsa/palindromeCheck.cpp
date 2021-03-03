#include <bits/stdc++.h>
using namespace std;
int isPalindrome(int A)
{
    if (A < 0)
        return 0;

    if (A == 0 || A < 10)
        return 1;
    int exp = (int)log10(A);

    int maxi = (int)pow(10, exp);
    // maxi = max(10, maxi);

    if (maxi == A)
        return 0;

    int c = 10;
    while (maxi >= c)
    {

        int a1 = A / maxi;
        int l1 = A % c;
        if (a1 != l1)
        {
            return 0;
        }

        A = A - (a1 * maxi);
        A = (A - l1) / 10;
        maxi = maxi / 100;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    cout << isPalindrome(n) << endl;
}