#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &t, int start, int end, int val)
{
    if (start >= end)
        return end;

    int mid = start + (end - start) / 2; // To prevent integer overflow

    if (val >= t[mid])
        return binarySearch(t, mid + 1, end, val);
    else
        return binarySearch(t, start, mid, val);
}

vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<int> t;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int it = binarySearch(t, 0, t.size(), obstacles[i]);
        if (it == t.size())
            t.push_back(obstacles[i]);
        else
            t[it] = obstacles[i];

        ans[i] = it + 1;
    }

    return ans;
}

int main()
{
    vector<int> obstacles = {3,1,5,6,4,2};
    vector<int> ans = longestObstacleCourseAtEachPosition(obstacles);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}