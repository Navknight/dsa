---
link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
difficulty: Hard
topics:
  - "[[Dynamic Programming]]"
  - "[[Binary Search]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "LIS with upper_bound (non-decreasing), answer at i = insert position + 1"
time: "O(n log n)"
space: "O(n)"
date: 
---

# Problem
For each `i`, longest non-decreasing subsequence ending at `i`.

# Approach
## DP
[[Longest Increasing Subsequence]] with `>=`.

### Code
```cpp
vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (obstacles[i] >= obstacles[j])
            {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$

## Patience Sorting
Upper bound (first `> x`) since equal heights are allowed. `ans[i]` = position + 1.

### Code
```cpp
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
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
