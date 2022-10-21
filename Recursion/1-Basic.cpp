// NyxCode

#include <bits/stdc++.h>

using namespace std;

#define fastNyxCode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

void say_i_am_top_coder(int n)
{
    if (n < 1)
        return;                 // Base Case
    cout << "I'm Top Coder.\n"; // Some Logic
    say_i_am_top_coder(n - 1);  // Sub-problem
}

int factorial(int a)
{
    if (a <= 1)
        return 1;
    return a * factorial(a - 1);
}

void triangle(int n)
{
    if (n <= 0)
        return;
    triangle(n - 1);
    for (int i = 1; i <= n; ++i)
        cout << "*";
    cout << endl;
}

// `3*n+1` series: if `n` is odd then `n = 3*n+1`, if `n` is even then `n = n/2`; if n == 1 stop.
int f3n_1(int n)
{
    if (n == 1)
        return 1;
    if (n & 1)
        return 1 + f3n_1(3 * n + 1);
    return 1 + f3n_1(n / 2);
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    vector<int> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int i = l, k = 0; i <= r; ++i, ++k)
        arr[i] = temp[k];
}

void print_digits(int n)
{
    if (n)
    {
        print_digits(n / 10);
        cout << n % 10 << '\n';
    }
}

void n_bits(int n)
{
    if (n)
    {
        n_bits(n / 2);
        cout << n % 2;
    }
}

signed main()
{
    fastNyxCode;
    n_bits(100);
    return 0;
}
