---
link: https://leetcode.com/problems/first-unique-character-in-a-string/
difficulty: Easy
topics:
  - "[[Hash Maps]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "count every char, then return the first index with count 1"
time: "O(n)"
space: "O(1)"
date: 2022-12-11
---

# Problem
Index of the first non-repeating character, or -1.

# Approach
## Count Twice
First pass counts, second pass finds the first count of 1.

Bug in my code: no `return -1` at the end.

### Code
```cpp
int firstUniqChar(string s)
{
    map<char, int> a;
    for (int i = 0; i < s.length(); i++)
    {
        if (a.find(s[i]) == a.end())
            a[s[i]] = 1;
        else
            a[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (a[s[i]] == 1)
            return i;
    }
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$, charset size
