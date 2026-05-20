---
difficulty: Medium
topics:
  - Sliding Window
  - Arrays
source: Leetcode
star: false
link: https://leetcode.com/problems/permutation-in-string/
date: 2026-05-20
---
[[Sliding Window]], [[Arrays]]


# Problem

if S2 contains a permutation of S1 as a substring

# Approach
Use arrays to track the frequency of $S1$ and the frequencies of characters in the substring of $S2$. Use `memcmp` to compare the arrays.
# Code

```cpp
bool checkInclusion(string s1, string s2) {
	int m = s1.size(), n = s2.size();
	if (n < m)
		return false;
	int freq[26] = {}, window[26] = {};

	for (char s : s1) {
		freq[s - 'a']++;
	}

	for (int i = 0; i < m; i++) {
		window[s2[i] - 'a']++;
	}

	for (int i = m; i < n; i++) {
		if (memcmp(freq, window, sizeof(freq)) == 0)
			return true;

		window[s2[i - m] - 'a']--;
		window[s2[i] - 'a']++;
	}

	return memcmp(freq, window, sizeof(freq)) == 0;
}
```

# Complexity
- Time: $O(n)$
- Space: $O(n)$
