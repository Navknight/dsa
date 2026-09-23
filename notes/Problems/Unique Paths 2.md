---
link: https://leetcode.com/problems/unique-paths-ii/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "1D dp from the bottom-right, t[j] += t[j+1], obstacle cells are 0"
time: "O(m * n)"
space: "O(n)"
date: 2023-06-02
---

# Problem
Count right/down paths in a grid with obstacles.

# Approach
## 1D DP
[[Unique Paths]] rolling array from the bottom-right. Obstacle cell = 0.

### Code
```cpp
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> t(n, 0);
    t[n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
        {
            if (obstacleGrid[i][j])
                t[j] = 0;
            else if (j + 1 < n)
                t[j] += t[j + 1];
        }
    return t[0];
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(n)$
