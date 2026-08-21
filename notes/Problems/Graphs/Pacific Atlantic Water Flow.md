---
difficulty: Medium
topics:
  - Graphs
  - DFS
  - Bit Manipulation
source: Leetcode
star: false
link: https://leetcode.com/problems/pacific-atlantic-water-flow/
date: 2026-08-22
---

[[Graphs]] [[DFS]] [[Bit Manipulation]] [[Surrounded Regions]]

# Problem
Given an `r x c` grid of heights, water can flow from a cell to any 4-directionally adjacent cell with height `<=` the current cell's height. Find all cells from which water can flow to both the Pacific (touches the top row or left column) and the Atlantic (touches the bottom row or right column).

# Approach
## Multi-Source DFS from Ocean Borders (reversed flow)
Tracing forward from every cell is wasteful, and a single directional sweep (say, top-left to bottom-right) doesn't work at all: whether a cell reaches an ocean can depend on a neighbor that's discovered *later* in scan order, and on a flat plateau two equal-height cells can depend on each other, so there's no acyclic fill order a straight sweep can rely on. Same reason a classic bottom-up DP table doesn't apply cleanly here.

So reverse the direction. Instead of asking "can this cell flow downhill to the ocean," start *at* the ocean border (already reachable by definition) and ask "which neighbors could flow down into a cell I've already marked reachable?" That's any neighbor with height `>= ` the current cell. Flood outward from every Pacific border cell (top row + left column) to get all Pacific-reachable cells, do the same from every Atlantic border cell (bottom row + right column), then intersect the two reachable sets.

Same pattern as [[Surrounded Regions]] — multi-source flood fill seeded from the border — just with a height comparison instead of a "same region" check.

Critical correctness detail: without a per-pass visited guard, two adjacent equal-height cells recurse into each other forever, since `height[ni][nj] >= height[i][j]` holds both ways on a plateau. Concrete case: a `2x2` grid of all `1`s — `(0,0) -> (1,0) -> (0,0) -> ...` with no base case, which stack-overflows. The guard must check "have I already marked this cell reachable *for this ocean*," and that check has to be safe regardless of which ocean's pass runs first.

### Bitmask Grid Version
Encode both oceans in one `int` grid: bit `1` = reaches Pacific, bit `2` = reaches Atlantic (`3` = both). `|=` merges a new bit in without erasing the other ocean's mark; `& comp` isolates just the bit the current pass cares about, so the guard works no matter which ocean floods first. Saves one `r x c` grid over the two-boolean-array version, at the cost of being less immediately readable.

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
- Time: $O(rc)$ — the bit guard means each cell is freshly marked at most twice (once per ocean bit)
- Space: $O(rc)$ for `goes`, plus up to $O(rc)$ recursion stack in the worst case

## Two Boolean Grids Version
Same algorithm, no bit tricks: one `pacific` grid and one `atlantic` grid, `dfs` takes whichever one is currently being flooded. Guard is a plain `!reach[ni][nj]` check. Slightly more space (two `r x c` bool grids instead of one `r x c` int grid) for clearer reasoning — no bitmask to decode later.

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
- Space: $O(rc)$ for the two boolean grids, plus recursion stack

## Why DP Doesn't Help
A bottom-up DP table needs a fill order where every cell's dependencies are already resolved when you reach it. Here, "can flow to an equal-or-lower neighbor" creates mutual dependencies on plateaus (two equal-height cells can depend on each other), so no row/column sweep order resolves both cleanly. Making DP work would require sorting cells by height and using Union-Find to merge plateau groups — strictly more machinery and $O(rc \log(rc))$ from the sort, which is worse than the $O(rc)$ flood fill above. The `goes`/`reach` grid in both versions above already functions as a memo table; it's memoized recursion (graph-shaped DP), just not expressible as a simple nested-loop table.
