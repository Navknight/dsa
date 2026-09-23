---
link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "sliding window with last-seen index, jump l past the previous occurrence"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Length of the longest substring with no repeated characters.

# Approach
## Sliding Window
Store the last index of each char. On a repeat inside the window, move `l` to one past it.

### Complexity
- Time: $O(n)$
- Space: $O(1)$, charset size
