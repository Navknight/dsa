---
difficulty: Medium
topics: ["Dynamic Programming", "Recursion"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/edit-distance/?envType=study-plan-v2&envId=dynamic-programming"
code: ../../../LeetCode/edit_distance.cpp
---

[[Dynamic Programming]] [[Recursion]]

Given two strings `word1` and `word2`, return _the minimum number of operations required to convert `word1` to `word2`_.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

# Solution

This Problem is similar to the [[Minimum Number of Deletions and Insertions]] except here we have the option to delete as well.

So we have the base case where either one of the strings is empty, so we will have to insert characters equal to the length of the non empty string.
Now if two characters are equal no change is required, if they aren't then we calculate the minimum of the cases where we replace, delete or insert character.
Now to delete a character we simply take a substring without the last char for word1 and keep word2 as it is.
For insert, we assume that we have inserted a character in word1 after the last char and we reduce the length of word2 by one since the last character got inserted to word1 and got matched
For replacement we assume we have replaced a character in word1 and matched it with word2 so we reduce the length of both word1 and word2 by one

# 
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

DP-Table
```cpp
int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    vector<int> prev(n + 1);
    for (int i = 0; i < n + 1; i++)
        prev[i] = i;
    vector<int> curr(n + 1);
    for (int i = 1; i < m + 1; i++)
    {
        curr[0] = i;
        for (int j = 1; j < n + 1; j++)
        {
            if(word1[i-1] == word2[j-1])
                curr[j] = prev[j-1];
            else
                curr[j] = 1 + min(min(prev[j-1], prev[j]), curr[j-1]);
        }
        prev = curr;
    }

    return curr[n];
}
```
