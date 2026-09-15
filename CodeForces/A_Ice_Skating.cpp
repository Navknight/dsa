#include <bits/stdc++.h>

using namespace std;

vector<int> par;

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        par[a] = b;
}

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    par = vector<int>(n);

    iota(par.begin(), par.end(), 0);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (x[i] == x[j] || y[i] == y[j])
                join(i, j);

    int count = -1;

    for (int i = 0; i < n; i++)
        if (par[i] == i)
            count++;

    cout << count << endl;
}