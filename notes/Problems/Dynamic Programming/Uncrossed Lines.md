---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/uncrossed-lines"
code: LeetCode/uncrossed_lines.cpp
---
[[LeetCode/uncrossed_lines.cpp]]
[[Dynamic Programming]]

# Problem
You are given two integer arrays `nums1` and `nums2`. We write the integers of `nums1` and `nums2` (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers `nums1[i]` and `nums2[j]` such that:

- `nums1[i] == nums2[j]`, and
- the line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return _the maximum number of connecting lines we can draw in this way_.

# Solution
This problem is just [[Longest Common Subsequence]] in a different form, the solution is exactly the same

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