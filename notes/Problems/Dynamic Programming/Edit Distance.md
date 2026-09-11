---
difficulty: Medium
topics: ["Dynamic Programming", "Recursion"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/edit-distance/?envType=study-plan-v2&envId=dynamic-programming"
code: LeetCode/edit_distance.cpp
---
	[[LeetCode/edit_distance.cpp]]
[[Dynamic Programming]] [[Recursion]]

Given two strings `word1` and `word2`, return _the minimum number of operations required to convert `word1` to `word2`_.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

# Solution

This Problem is similar to the [[Minimum Number of Deletions and Insertions]] except here we have the option to replace as well.

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

Suffix version of the same table, space optimized. Here `dp[i][j]` is min ops to convert `word1[i:]` to `word2[j:]`, `prev` holds row `i+1`, `curr` holds row `i`. On a match we need the diagonal `dp[i+1][j+1]`, so `prev[j+1]` not `prev[j]`.

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
