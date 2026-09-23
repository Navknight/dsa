---
link: https://leetcode.com/problems/zigzag-conversion/
difficulty: Medium
topics:
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "one string per row, walk rows down then up, concatenate"
time: "O(n)"
space: "O(n)"
date: 2023-02-01
---

# Problem
Write `s` in a zigzag over `numRows` rows, read row by row.

# Approach
## Row Buckets
Append chars to row `0..numRows-1`, then back up to 1, repeat. Concatenate the rows. `numRows == 1` returns `s`.

### Code
```cpp
string convert(string s, int numRows) {
    if(numRows == 1) return s;
        int n = s.length();
        int i = 0;
        vector<string> r(numRows, "");
        while(i < n){
            int j = (i == 0)? 0: 1;
            while(j < numRows && i < n){
                r[j] = r[j] + s[i];
                i++;j++;
            }
            j -= 2;
            while(j >= 0 && i < n){
                r[j] = r[j] + s[i];
                i++;j--;
            }
        }
        string ans = "";
        for(int j = 0; j < numRows; j++)
            ans = ans+r[j];
        return ans;
    }
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
