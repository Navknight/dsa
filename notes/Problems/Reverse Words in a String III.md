---
link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
difficulty: Easy
topics:
  - "[[Strings]]"
  - "[[Two Pointers]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "reverse each space-separated word in place"
time: "O(n)"
space: "O(1)"
date: 2022-12-16
---

# Problem
Reverse the characters of each word, keep word order.

# Approach
## Reverse Each Word
On every space, reverse `[start, i-1]`, then the last word. Pass `s` by reference, returning copies makes it O(n²).

### Code
```cpp
string reverse(string s, int start, int end)
{
    int mid = (start + end) / 2;
    while (start <= mid)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

string reverseWords(string s)
{
    int n = s.size();
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 32)
        {
            end = i - 1;
            s = reverse(s, start, end);
            start = i + 1;
        }
    }
    s = reverse(s, start, n - 1);
    return s;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
