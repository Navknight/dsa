---
link: https://leetcode.com/problems/ransom-note/
difficulty: Easy
topics:
  - "[[Hash Maps]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "count magazine chars, decrement per note char, fail on 0"
time: "O(n + m)"
space: "O(1)"
date: 2022-12-11
---

# Problem
Can `ransomNote` be built from `magazine`'s letters?

# Approach
## Count
Count magazine chars, spend one per note char. Missing or 0 = false.

### Code
```cpp
bool canConstruct(string ransomNote, string magazine)
{
    map<char, int> a;
    for (int i = 0; i < magazine.length(); i++)
    {
        if (a.find(magazine[i]) == a.end())
            a[magazine[i]] = 1;
        else
            a[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (a.find(ransomNote[i]) == a.end())
            return false;
        else
        {
            if (a[ransomNote[i]] == 0)
                return false;
            else
                a[ransomNote[i]]--;
        }
    }
    return true;
}
```

### Complexity
- Time: $O(n + m)$
- Space: $O(1)$, charset size
