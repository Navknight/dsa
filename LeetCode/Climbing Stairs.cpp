#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> a = {{1, 1}, {2, 2}};

int climbStairs(int n)
{
    if (a.find(n) != a.end())
        return a[n];
    else
    {
        a[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return a[n];
    }
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}