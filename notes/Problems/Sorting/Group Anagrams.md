---
difficulty: Medium
topics: ["Sorting"]
source: Leetcode
star: false
code: ../../../LeetCode/group_anagrams.cpp
---

[[Sorting]]

 [Group Anagrams]([Group Anagrams - LeetCode](https://leetcode.com/problems/group-anagrams/?envType=study-plan&id=programming-skills-ii))   

Anagrams when sorted give the same word, so we sort every word in the array and store them accordingly in a map, which we then return in the form of an array of arrays.

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> map;
	for(auto str : strs){
		string s = str;
		sort(s.begin(), s.end());
		map[s].push_back(str);
	}

	for(auto i: map){
		ans.push_back(i.second);
	}

	return ans;
}
```