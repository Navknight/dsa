---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
---

[[Dynamic Programming
# Problem
[Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
Given two strings `s1` and `s2`, return _the lowest **ASCII** sum of deleted characters to make two strings equal_.

# Solution

This problem is a variation of [[Longest Common Subsequence]] problem, here we add the ASCII number of that character to find the minimum delete value.

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