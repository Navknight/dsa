---
link: https://leetcode.com/problems/set-matrix-zeroes/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-11
insight: "record zero rows and cols first, then clear. O(1): use row 0 and col 0 as the markers"
time: "O(m * n)"
space: "O(m + n)"
date: 2026-11-08
---

# Problem
If a cell is 0, set its whole row and column to 0, in place.

# Approach
## Mark then Clear
Record which rows and columns have a 0, then clear them. For O(1) space, store the marks in row 0 and column 0.

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m + n)$

- First row and column are the markers. Record `row0` and `col0` flags first, they say the border originally had a zero
- Clear the interior first, the border last. Clearing the border early destroys markers
- Tests: `[[0,1],[1,1]]`, `[[1,0],[1,1]]`, and the 3x3 with a centre zero

### Mistakes
- Had the last two conditions inverted, `if (!row0)`. Clear when the flag is true
