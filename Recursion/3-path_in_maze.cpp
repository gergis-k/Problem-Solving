// NyxCode

#include <bits/stdc++.h>

using namespace std;

#define fastNyxCode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define MAX 100

int n, m;

char grid[MAX][MAX];
bool visited[MAX][MAX];

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool find_end(int i, int j)
{
    if (!valid(i, j) || grid[i][j] == 'X' || visited[i][j])
        return false;

    visited[i][j] = true;

    if (grid[i][j] == 'E')
        return true;

    // try 4 neighbours
    // right
    if (find_end(i, j + 1))
        return true;
    // down
    if (find_end(i + 1, j))
        return true;
    // left
    if (find_end(i, j - 1))
        return true;
    // up
    if (find_end(i - 1, j))
        return true;

    visited[i][j] = false;

    return false;
}

signed main()
{
    fastNyxCode;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    // search for S
    int si, sj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'S')
                si = i, sj = j;

    if (find_end(si, sj))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
