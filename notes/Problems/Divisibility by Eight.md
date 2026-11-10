---
link: https://codeforces.com/problemset/problem/550/C
rating: 1500
contest: Codeforces Round 306 (Div 2)
topics:
  - "[[Brute Force]]"
  - "[[Dynamic Programming]]"
  - "[[Math]]"
source: CodeForces
star: true
mastery: red
review: 2026-10-23
insight: "1000 % 8 == 0 so only the last 3 digits matter. Try every subsequence of length 1, 2, 3"
time: "O(n³)"
space: "O(1)"
date: 2026-10-20
code: "[[CodeForces/C_Divisibility_by_Eight.cpp]]"
---

# Problem
Number with up to 100 digits. Cross out some digits so the rest is divisible by 8, no leading zeros. Print it or NO.

# Observation
1000 is divisible by 8, so a number is divisible by 8 iff its last 3 digits are. Any answer trims to at most 3 digits. Triple loop over i < j < k.
- A single 0 is valid. Longer numbers can't start with 0.

DP alternative (generalizes to any k): only the remainder mod 8 matters, since (r*10 + d) % 8 depends only on r. dp[i][r] over take/skip, 100 * 8 states. Rebuild the number by replaying choices or with prev pointers.

Traps:
- First try deleted digits recursively with a string memo. 2^100 states, and stoi crashed on long input. Samples passed anyway.
- Memo key has to be (i, r), not the string.
