#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string A)
{
    int n = A.length();
    int i = 0;
    int rs = 0;
    while (i < n)
    {
        int exp = A[n - i - 1] - 'A' + 1;
        rs += exp * pow(26, i);
        i++;
    }
    return rs;
}
int main()
{
    string a;
    cin >> a;

    cout << titleToNumber(a) << endl;
}