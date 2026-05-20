---
difficulty: Easy
topics: ["Arrays", "Hash Maps"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/two-sum/description/"
---

[[Arrays]] [[Hash Maps]]

# Map
The array should contain the `num\[i\]` and the `target - nums\[i\]`
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	int n = nums.size();
	for(int i = 0; i < n; i++){
		if(map.find(target - nums[i]) != map.end())
			return {map[target - nums[i]],i};
		map[nums[i]] = i;
	}
	return {};
}
```
