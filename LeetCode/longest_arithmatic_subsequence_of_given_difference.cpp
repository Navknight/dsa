#include <bits/stdc++.h>

using namespace std;

int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    unordered_map<int, int> t;
    int max_length = 1;

    for (int i = 0; i < n; i++)
    {
        if (t.find(arr[i] - difference) != t.end())
        {
            t[arr[i]] = t[arr[i] - difference] + 1;
        }
        else
            t[arr[i]] = 1;
        max_length = max(max_length, t[arr[i]]);
    }
    return max_length;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 7, 7, 7};
    cout << longestSubsequence(arr, 0) << endl;
    return 0;
}