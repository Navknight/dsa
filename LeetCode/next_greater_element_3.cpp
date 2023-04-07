#include <bits/stdc++.h>

using namespace std;

int nextGreaterElement(int n)
{
    string s = to_string(n);
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0)
        return -1;
    int j = s.size() - 1;
    while (j >= 0 && s[j] <= s[i])
        j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    long long res = stoll(s);
    return res > INT_MAX ? -1 : res;
}

int main()
{
    int n = 21;
    cout << nextGreaterElement(n) << endl;
    return 0;
}