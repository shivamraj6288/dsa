#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    unordered_set<int> rows;
    unordered_set<int> columns;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 0)
            {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }
    unordered_set<int>::iterator itr;
    itr = rows.begin();
    while (itr != rows.end())
    {
        for (int i = 0; i < n; i++)
        {
            A[*itr][i] = 0;
        }
        itr++;
    }
    itr = columns.begin();
    while (itr != columns.end())
    {
        for (int i = 0; i < m; i++)
        {
            A[i][*itr] = 0;
        }
        itr++;
    }
    int main(){
        
    }
}
