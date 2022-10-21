// NyxCode

#include <bits/stdc++.h>

using namespace std;

#define fastNyxCode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define MAX 100

/*
    Problem: Given a grid of size n*m, find the maximum sum path from top left to bottom right.
    You can only move right or down.
*/

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int n, m;
int grid[MAX][MAX];

int maxSumPath(int i, int j)
{
    if (!valid(i, j))
        return 0;
    // base case
    if (i == n - 1 && j == m - 1)
        return grid[i][j];
    // right
    int right = maxSumPath(i, j + 1);
    // down
    int down = maxSumPath(i + 1, j);

    return grid[i][j] + max(right, down);
}

signed main()
{
    fastNyxCode;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << maxSumPath(0, 0) << endl;

    return 0;
}