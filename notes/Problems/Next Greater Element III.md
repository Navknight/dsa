---
link: https://leetcode.com/problems/next-greater-element-iii/
difficulty: Medium
topics:
  - "[[Math]]"
  - "[[Two Pointers]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "next permutation of the digits, -1 if it overflows int"
time: "O(d)"
space: "O(d)"
date: 
---

# Problem
Smallest number greater than `n` with the same digits, or -1.

# Approach
## Next Permutation
From the right, find the first digit smaller than the one after it. Swap it with the rightmost bigger digit, then reverse the suffix. -1 if none or it overflows int.

### Code
```cpp
int nextGreaterElement(int n)
{
    string s = to_string(n);
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0)
        return -1;
    int j = s.size() - 1;
    while (j >= 0 && s[j] <= s[i])
        j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    long long res = stoll(s);
    return res > INT_MAX ? -1 : res;
}
```

### Complexity
- Time: $O(d)$
- Space: $O(d)$
