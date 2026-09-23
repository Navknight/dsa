---
link: https://leetcode.com/problems/minimum-path-sum/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "t[i][j] = grid[i][j] + min(top, left)"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
Min sum path from top-left to bottom-right, moving right or down.

# Approach
## Forward DP
`t[i][j] = grid[i][j] + min(t[i-1][j], t[i][j-1])`. Like [[Unique Paths]].

### Code
```cpp
int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> t(grid.size(), vector<int>(grid[0].size(), 0));
    t[0][0] = grid[0][0];
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[0].size(); j++)
        {
            int x = INT32_MAX, y = INT32_MAX;
            if(i == 0 && j == 0)
                continue;
            if (i >= 1)
                y = t[i - 1][j];
            if (j >= 1)
                x = t[i][j - 1];
            t[i][j] = min(x, y) + grid[i][j];
        }
    }
    return t[t.size() - 1][t[0].size() - 1];
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
