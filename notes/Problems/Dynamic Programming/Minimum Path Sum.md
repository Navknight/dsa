---
difficulty: Medium
topics: ["Dynamic Programming", "Matrix"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/minimum-path-sum/?envType=study-plan-v2&envId=dynamic-programming"
---

[[Dynamic Programming]] [[Matrix]]

# # 
we create a solution matrix `t` which will hold the cost to reach every cell from the start.
The way we calculate it is, that for each cell we add -> `min(grid[i-1][j], grid[i][j-1])` to `grid[i][j]`.
This value gives the minimum of the cost to reach that cell as only the downward and rightward movements are allowed. This has a similar feel to the [[Unique Paths]] problem as here also we have to make a choice between going down or going right based on the minimum possible cost, but instead of traversing backward we are traversing forward here. However we can solve this problem by traversing backward as well.

## Forward traversal
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

## Backward Traversal
![[Pasted image 20230530173239.png]]

The backward solution is from Neetcode.