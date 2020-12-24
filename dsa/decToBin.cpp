#include <bits/stdc++.h>
using namespace std;

string findDigitsInBinary(int A)
{
    string rs;
    int q = A;
    while (q != 1 && q != 0)
    {
        if (q % 2 == 0)
            rs = "0" + rs;
        else
        {
            rs = "1" + rs;
        }
        q = q / 2;
    }
    rs = to_string(q) + rs;
    return rs;
}
int main()
{
    int a;
    cin >> a;

    cout << findDigitsInBinary(a) << endl;
}