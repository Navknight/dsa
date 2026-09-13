---
difficulty: Easy
topics:
  - Sorting
source: CodeForces
star: false
link: https://codeforces.com/problemset/problem/405/A
code: CodeForces/A_Gravity_Flip.cpp
date: 2026-09-13
---

[[CodeForces/A_Gravity_Flip.cpp]]
[[Sorting]]

# Problem
Columns of cubes. Gravity switches to pull right. Print the new column heights.

# Approach
## Sort
Cubes fall right so heights end up in non-decreasing order. Just sort.

### Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (auto &num : a)
    {
        cout << num << " ";
    }
    cout << endl;
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
