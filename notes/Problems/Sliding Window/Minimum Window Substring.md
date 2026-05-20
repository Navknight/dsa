---
difficulty: Hard
topics: ["Sliding Window"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04"
---

[[Sliding Window]]

# Problem
Given two strings `s` and `t` of lengths `m` and `n` respectively, return _the **minimum window**_ **_substring_**  _of_ `s` _such that every character in_ `t` _(**including duplicates**) is included in the window_. If there is no such substring, return _the empty string_ `""`.The testcases will be generated such that the answer is **unique**.

# Solution
```cpp
string minWindow(string s, string t) {
	int m = s.size(), n = t.size();
	if(n > m) return "";

	unordered_map<char, int> map;
	for(char c : t) map[c]++;

	int counter = n;
	int left = 0, right = 0;
	int length = INT32_MAX;
	pair<int, int> ans = {0,0};

	while(right < m) {
		if(map.find(s[right]) != map.end()){
			if(map[s[right]] > 0) counter--;
			map[s[right]]--;
		}

		while(counter == 0) {
			if((right - left + 1) < length){
				length = right - left + 1;
				ans = {left, length};
			}

			if(map.find(s[left]) != map.end()){
				map[s[left]]++;
				if(map[s[left]] > 0) counter++;
			}
			left++;
		}
		right++;
	}

	return s.substr(ans.first, ans.second);
}
```

## Avoid memory limit exceed
