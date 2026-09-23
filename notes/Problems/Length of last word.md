---
link: https://leetcode.com/problems/length-of-last-word/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "skip trailing spaces from the back, then count until a space"
time: "O(n)"
space: "O(1)"
date: 2023-03-30
---

# Problem
Length of the last word in a string.

# Approach
## Scan from the Back
Skip trailing spaces, count chars until the next space.

### Code
```cpp
int lengthOfLastWord(string s) {
        int ind = s.size() - 1;
        while(ind>= 0 && s[ind] == ' '){
            ind--;
        }
        int count = 0;
        while (ind >= 0 && s[ind] != ' '){
            ind--;
            count++;
        }
        return count;
    }
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
