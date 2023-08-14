#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &t, int start, int end, int val)
{
    if (start >= end)
        return end;

    int mid = start + (end - start) / 2;  // To prevent integer overflow

    if (val == t[mid])
        return mid;
    else if (val > t[mid])
        return binarySearch(t, mid + 1, end, val);
    else
        return binarySearch(t, start, mid - 1, val);
}


vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<int> ans(n, 1);
    vector<int> t;

    for (int i = 0; i < n; i++)
    {
        if (t.size() == 0 || t[t.size() - 1] <= obstacles[i])
        {
            t.push_back(obstacles[i]);
            int it = t.size();
            ans[i] = it;
        }
        else
        {
            int it = binarySearch(t, 0, t.size() - 1, obstacles[i]);
            t.insert(t.begin() + it++, obstacles[i]);
            ans[i] = it + 1;
        }
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