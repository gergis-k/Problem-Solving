// NyxCode

#include <bits/stdc++.h>

using namespace std;

#define fastNyxCode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define X first
#define Y second
#define clr(x) memset(x, 0, sizeof(x))
#define clrm1(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(all(x))
#define revall(x) reverse(all(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mapii;
typedef map<ll, ll> mapll;
typedef map<string, int> mapsi;
typedef map<char, int> mapci;

// https://codeforces.com/problemset/problem/1256/F

void fire()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    mapci m, res;

    for (int i = 'a'; i <= 'z'; ++i)
    {
        m[i] = 0;
        res[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        ++m[s[i]];
        ++res[t[i]];
    }
    int check = 0, ans = 0;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (m[i] != res[i])
        {
            check = 1;
            break;
        }
        if (m[i] >= 2)
            ++ans;
    }
    if (check)
    {
        cout << "NO" << endl;
        return;
    }
    if (ans)
    {
        cout << "YES" << endl;
        return;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
                ++cnt;
            }
            if (t[j] > t[j + 1])
            {
                swap(t[j], t[j + 1]);
                ++cnt;
            }
        }
    }
    if (cnt % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    fastNyxCode;

    int t = 1;
    cin >> t;
    while (t--)
        fire();

    return 0;
}
