---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/delete-operation-for-two-strings/description/"
---

[[Dynamic Programming]]

# Problem
Given two strings `word1` and `word2`, return _the minimum number of **steps** required to make_ `word1` _and_ `word2` _the same_.

In one **step**, you can delete exactly one character in either string.

# Solution
This problem is the same as [[Longest Common Subsequence]] problem, except we return a different thing.

```cpp
int minDistance(string word1, string word2) {
	int n = word1.size(); int m = word2.size();
	vector<vector<int>> t(n+1, vector<int>(m+1));

	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < m+1; j++){
			if(i == 0 || j == 0)
				t[i][j] = 0;
			else{
				if(word1[i-1] == word2[j-1])
					t[i][j] = t[i-1][j-1] + 1;
				else
					t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}

	int l = t[n][m];
	return n - l + m - l;
}
```
