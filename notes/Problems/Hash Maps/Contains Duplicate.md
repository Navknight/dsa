---
difficulty: Easy
topics: ["Arrays", "Hash Maps"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/contains-duplicate/description/"
---

[[Arrays]] [[Hash Maps]]

# Map
```cpp
bool containsDuplicate(vector<int>& nums) {
	unordered_map<int, bool> map;
	int n = nums.size();
	for(int i = 0; i < n; i++){
		if(map.find(nums[i]) != map.end())
			return true;
		map[nums[i]] = true;
	}

	return false;
}
```

# Set
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int num : nums) {
        if(seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
```
