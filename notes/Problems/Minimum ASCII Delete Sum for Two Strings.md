---
link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "LCS weighted by ASCII, answer = sum(s1) + sum(s2) - 2 * best common"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
Min ASCII sum of deleted chars to make two strings equal.

# Approach
## Weighted LCS
[[Longest Common Subsequence]] but a match adds the char's ASCII value. Delete everything else.

### Code
```cpp
int asciisum(string s){
        int sum = 0;
        for(char i: s)
            sum += i;
        return sum;
    }
int minimumDeleteSum(string s1, string s2) {
    vector<vector<int>> t(s1.size() + 1, vector<int> (s2.size()+ 1));
    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else{
                if(s1[i-1] == s2[j-1])
                    t[i][j] = t[i-1][j-1] + s1[i-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return asciisum(s1) + asciisum(s2) - 2*t[s1.size()][s2.size()];
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
