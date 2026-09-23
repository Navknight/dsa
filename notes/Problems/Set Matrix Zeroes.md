---
link: https://leetcode.com/problems/set-matrix-zeroes/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "record zero rows and cols first, then clear. O(1): use row 0 and col 0 as the markers"
time: "O(m * n)"
space: "O(m + n)"
date: 
---

# Problem
If a cell is 0, set its whole row and column to 0, in place.

# Approach
## Mark then Clear
Record which rows and columns have a 0, then clear them. For O(1) space, store the marks in row 0 and column 0.

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m + n)$
