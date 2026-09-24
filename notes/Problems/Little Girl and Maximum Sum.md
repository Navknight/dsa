---
link: https://codeforces.com/problemset/problem/276/C
rating: 1500
contest: Codeforces Round 170 (Div 1)
topics:
  - "[[Prefix Sum]]"
  - "[[Arrays]]"
source: CodeForces
star: false
blind75: false
mastery: yellow
review: 2026-09-27
insight: We can use the prefix sum to calculate frequency of elements in an interval by creating a diff array of `diff[l]++; diff[r+1]--` first then prefix summing the diff array
time: O(n)
space: O(n)
date: 2026-09-24
code: "[[CodeForces/C_Little_Girl_and_Maximum_Sum.cpp]]"
---

# Problem
Given an array and q queries `(l, r)` each adding the range sum, permute the array once beforehand to maximize the total over all queries.

# Observation
Rearrangement inequality: the indices asked for most often should hold the largest elements, in decreasing order of frequency.

To get the frequency of each index in O(n) instead of O(nq), build a `diff` array: `diff[l]++, diff[r+1]--` per query, then prefix-sum it once. Sort frequency and the array the same direction, pair index by index.