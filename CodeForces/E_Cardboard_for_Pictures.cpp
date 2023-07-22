#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, c;
        cin >> n, c;
        vector<int> s(n);
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            sum += s[i] * s[i];
        }
        
    }
    return 0;
}