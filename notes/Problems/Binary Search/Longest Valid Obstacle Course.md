---
difficulty: Hard
topics: ["Binary Search", "Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/"
---

[[Binary Search]] [[Dynamic Programming]]

# Problem
You want to build some obstacle courses. You are given a **0-indexed** integer array `obstacles` of length `n`, where `obstacles[i]` describes the height of the `ith` obstacle.

For every index `i` between `0` and `n - 1` (**inclusive**), find the length of the **longest obstacle course** in `obstacles` such that:

- You choose any number of obstacles between `0` and `i` **inclusive**.
- You must include the `ith` obstacle in the course.
- You must put the chosen obstacles in the **same order** as they appear in `obstacles`.
- Every obstacle (except the first) is **taller** than or the **same height** as the obstacle immediately before it.

Return _an array_ `ans` _of length_ `n`, _where_ `ans[i]` _is the length of the **longest obstacle course** for index_ `i` _as described above_.

# Solution
1. **DP Solution without optimization**
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

2. **Optimized Solution**
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
