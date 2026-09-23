---
link: https://leetcode.com/problems/edit-distance/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
  - "[[Recursion]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "match: dp[i-1][j-1], else 1 + min(insert, delete, replace)"
time: "O(m * n)"
space: "O(n)"
date: 2023-07-27
---

# Problem
Min insert, delete or replace ops to turn `word1` into `word2`.

# Approach
Like [[Delete Operation for Two Strings]] plus replace. Empty string base = length of the other. Match: no op. Else `1 + min(replace, delete, insert)`.

## Recursion

### Code
```cpp
 int minDistance(string word1, string word2)
 {
     int m = word1.size(), n = word2.size();
     if (m == 0)
         return n;
     if (n == 0)
         return m;
     if (word1[m - 1] == word2[n - 1])
         return minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1));
     else
     {
         int replace = minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1));
         int del = minDistance(word1.substr(0, m - 1), word2.substr(0, n));
         int ins = minDistance(word1.substr(0, m), word2.substr(0, n - 1));

        return 1 + min(min(replace, del), ins);
    }
}
```

### Complexity
- Time: $O(3^{m+n})$
- Space: $O(m+n)$

## Prefix DP, 1D
Row 0 = inserts, column 0 = deletes. Replace = `prev[j-1]`, insert = `curr[j-1]`, delete = `prev[j]`.

### Code
```cpp
int minDistance(string word1, string word2) {
    // prefix based dp - Q that I ask is, what do I need to do to match the first i characters
    // of word1 to the first j characters of word2.
    int m = word1.size(), n = word2.size();
    if (n == 0) return m;
    if (m == 0) return n;

    vector<int> prev(n + 1);
    iota(prev.begin(), prev.end(), 0);  // this is when word1 is empty, so I have no choice but
                                        // to insert the number of characters required.
    vector<int> curr(n + 1);

    for (int i = 1; i < m + 1; i++) {
        curr[0] = i;  // the first column is word2 empty, so I have no choice but to delete the
                      // number of characters in word1.
        for (int j = 1; j < n + 1; j++) {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = prev[j - 1];  // if word1 == word2, no operations are reuired, we just
                                        // carry the operations till now in memory forward.
            else
                curr[j] = 1 + min({
                                  prev[j - 1],  // replace a char
                                  curr[j - 1],  // insert a char
                                  prev[j]       // delete a char
                              });
        }
        prev = curr;
    }

    return curr[n];
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(n)$

## Suffix DP, 1D
`dp[i][j]` = ops for `word1[i:]` to `word2[j:]`. On a match use the diagonal `prev[j+1]`.

### Code
```cpp
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    if (n == 0) return m;
    if (m == 0) return n;

    vector<int> prev(n + 1);
    for (int i = 0; i < n + 1; i++) prev[i] = n - i;
    vector<int> curr(n + 1);

    for (int i = m - 1; i >= 0; i--) {
        curr[n] = m - i;
        for (int j = n - 1; j >= 0; j--) {
            if (word1[i] == word2[j])
                curr[j] = prev[j + 1];
            else
                curr[j] = 1 + min({curr[j + 1], prev[j], prev[j + 1]});
        }
        prev = curr;
    }

    return curr[0];
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(n)$
