#include <bits/stdc++.h>
using namespace std;

string titleToNumber(int A)
{
    string rs;
    int q = A;
    while (q > 26)
    {
        int r = q % 26;
        if (r == 0)
            r = 26;
        r = r - 1;
        char add = 'A' + r;
        r++;
        if (r == 26)
            r = 0;
        rs = add + rs;
        q = q / 26;
        // cout << q << endl
        //      << r << endl;
        if (r == 0)
            q = q - 1;
    }
    // cout << q;
    char add = 'A' + q - 1;
    rs = add + rs;
    return rs;
}
int main()
{
    // int a;
    // cin >> a;

    // cout << titleToNumber(a) << endl;
    for (int i = 1; i < 1080; i++)
    {
        cout << titleToNumber(i) << " ";
        if (i % 26 == 0)
            cout << endl;
    }
    cout << endl;
}