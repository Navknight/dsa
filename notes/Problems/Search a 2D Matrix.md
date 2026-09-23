---
link: https://leetcode.com/problems/search-a-2d-matrix/
difficulty: Medium
topics:
  - "[[Binary Search]]"
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "treat it as one sorted array of m * n, index mid -> (mid / n, mid % n)"
time: "O(log(m * n))"
space: "O(1)"
date: 2022-12-10
---

# Problem
Search a matrix where each row is sorted and each row starts after the previous ends.

# Approach
## Flattened Binary Search
Binary search over `0..m*n-1`, map `mid` to `(mid / n, mid % n)`.

### Code
```cpp
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        int x = (mid / n < m) ? mid / n : mid / n - 1;
        int y = (mid % n < n) ? mid % n : mid % n - 1;
        if (matrix[x][y] == target)
            return true;
        else if (target > matrix[x][y])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
```

### Complexity
- Time: $O(\log(m \cdot n))$
- Space: $O(1)$
