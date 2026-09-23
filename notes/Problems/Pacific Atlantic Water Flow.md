---
link: https://leetcode.com/problems/pacific-atlantic-water-flow/
difficulty: Medium
topics:
  - "[[Graphs]]"
  - "[[DFS]]"
  - "[[Bit Manipulation]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "reverse the flow, DFS uphill from each ocean's border, answer = cells reached by both"
time: "O(r * c)"
space: "O(r * c)"
date: 2026-08-22
---

# Problem
Cells from which water can flow to both the Pacific (top, left) and Atlantic (bottom, right).

# Approach
Forward sweeps fail, plateaus make equal cells depend on each other. Reverse it: flood from each ocean's border into neighbours with height `>=`, intersect the two sets. Same pattern as [[Surrounded Regions]].

Trap: without a visited check per ocean, equal-height neighbours recurse forever.

## Bitmask Grid
Bit 1 = Pacific, bit 2 = Atlantic, `3` = both. `|=` to mark, `& comp` to check.

### Code
```cpp
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& goes, int i, int j, int comp) {
        for (int d = 0; d < 4; d++) {
            int ni = dy[d] + i;
            int nj = dx[d] + j;

            if (ni >= 0 && nj >= 0 && ni < (int)heights.size() &&
                nj < (int)heights[0].size() && heights[ni][nj] >= heights[i][j] &&
                !(goes[ni][nj] & comp)) {
                goes[ni][nj] |= comp;
                dfs(heights, goes, ni, nj, comp);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> goes(r, vector<int>(c, 0));

        for (int j = 0; j < c; j++) {
            goes[0][j] |= 1;
            dfs(heights, goes, 0, j, 1);
        }
        for (int i = 0; i < r; i++) {
            goes[i][0] |= 1;
            dfs(heights, goes, i, 0, 1);
        }

        for (int j = 0; j < c; j++) {
            goes[r - 1][j] |= 2;
            dfs(heights, goes, r - 1, j, 2);
        }
        for (int i = 0; i < r; i++) {
            goes[i][c - 1] |= 2;
            dfs(heights, goes, i, c - 1, 2);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (goes[i][j] == 3)
                    ans.push_back({i, j});

        return ans;
    }
};
```

### Complexity
- Time: $O(rc)$
- Space: $O(rc)$

## Two Bool Grids
Same with `pacific` and `atlantic` grids.

### Code
```cpp
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reach, int i, int j) {
        for (int d = 0; d < 4; d++) {
            int ni = dy[d] + i;
            int nj = dx[d] + j;

            if (ni >= 0 && nj >= 0 && ni < (int)heights.size() &&
                nj < (int)heights[0].size() && heights[ni][nj] >= heights[i][j] &&
                !reach[ni][nj]) {
                reach[ni][nj] = true;
                dfs(heights, reach, ni, nj);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        for (int j = 0; j < c; j++) {
            pacific[0][j] = true;
            dfs(heights, pacific, 0, j);
        }
        for (int i = 0; i < r; i++) {
            pacific[i][0] = true;
            dfs(heights, pacific, i, 0);
        }

        for (int j = 0; j < c; j++) {
            atlantic[r - 1][j] = true;
            dfs(heights, atlantic, r - 1, j);
        }
        for (int i = 0; i < r; i++) {
            atlantic[i][c - 1] = true;
            dfs(heights, atlantic, i, c - 1);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
```

### Complexity
- Time: $O(rc)$
- Space: $O(rc)$
