---
link: https://leetcode.com/problems/uncrossed-lines/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "it's LCS on the two arrays"
time: "O(n * m)"
space: "O(n * m)"
date: 2023-08-15
---

# Problem
Max non-crossing lines between equal numbers of two arrays.

# Approach
## LCS
Exactly [[Longest Common Subsequence]].

### Code
```cpp
int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else{
                if(nums1[i-1] == nums2[j-1])
                    t[i][j] = t[i-1][j-1] + 1;
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[n][m];
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n \cdot m)$
