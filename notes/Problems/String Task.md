---
link: https://codeforces.com/problemset/problem/118/A
rating: 1000
contest: Codeforces Beta Round 89 Div 2
topics:
  - "[[Strings]]"
  - "[[Implementation]]"
source: CodeForces
star: false
blind75: false
mastery:
review:
insight: "lowercase everything, drop vowels, print '.' before each remaining char"
time: "O(n)"
space: "O(n)"
date: 2026-09-22
code: "[[CodeForces/A_String_Task.cpp]]"
---

# Problem
Delete vowels, lowercase the rest, put a dot before every remaining consonant.

# Observation
`y` counts as a vowel here. Lowercase before the vowel check, else uppercase vowels survive.
