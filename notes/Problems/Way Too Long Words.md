---
link: https://codeforces.com/problemset/problem/71/A
rating: 800
contest: Codeforces Beta Round 71
topics:
  - "[[Strings]]"
  - "[[Implementation]]"
source: CodeForces
star: false
blind75: false
mastery:
review:
insight: "len > 10 prints first char, len - 2, last char"
time: "O(n)"
space: "O(1)"
date: 2026-09-22
code: "[[CodeForces/A_Way_Too_Long_Words.cpp]]"
---

# Problem
Abbreviate every word longer than 10 chars as first letter, count of letters between, last letter.

# Observation
The count is `len - 2`, not `len`. Words of exactly 10 stay as they are.
