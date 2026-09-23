---
link: https://leetcode.com/problems/triangle/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "start from the last row, t[j] = val + min(t[j], t[j+1]) going up"
time: "O(n²)"
space: "O(n)"
date: 2023-03-11
---

# Problem
Min path sum from top to bottom of a triangle.

# Approach
## Bottom-Up 1D
Copy the last row, go up: `t[j] = triangle[i][j] + min(t[j], t[j+1])`. Answer `t[0]`.

### Code
```cpp
int minimumTotal(vector<vector<int>> &triangle)
{
    vector<int> t(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j<= triangle[i].size() - 1; j++)
        {
            t[j] = triangle[i][j] + min(t[j], t[j+1]);
        }
    }
    return t[0];
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$
