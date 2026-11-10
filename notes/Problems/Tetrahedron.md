---
link: https://codeforces.com/problemset/problem/166/E
rating: 1500
contest: Codeforces Round 113 (Div 2)
topics:
  - "[[Dynamic Programming]]"
  - "[[Math]]"
source: CodeForces
star: true
mastery: yellow
review: 2026-10-27
insight: "A, B, C are symmetric so the state is just at D or not. d' = o, o' = 3d + 2o"
time: "O(n)"
space: "O(1)"
date: 2026-10-20
code: "[[CodeForces/E_Tetrahedron.cpp]]"
---

# Problem
Ant starts at D on a tetrahedron, moves along an edge each step. Count ways to be back at D after n steps, mod 1e9+7. n up to 1e7.

# Observation
Only D vs not D matters. d = ways at D, o = ways at any of A, B, C.
- D to not D: 3 moves. Not D to D: 1 move. Not D to not D: 2 moves.
- So d' = o, o' = 3d + 2o. Start d = 1, o = 0. Two variables, no 1e7 array.
- Closed form: (3^n + 3(-1)^n) / 4.

Traps:
- `#define mod 1e9 + 7` is a double, `%` won't compile. Use `const ll mod`.
- Helpers took `int`, 3d overflowed. Samples passed, n = 100 was wrong. Use ll everywhere.
