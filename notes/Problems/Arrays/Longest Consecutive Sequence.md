---
difficulty: Medium
topics: []
source: Leetcode
star: false
link: "https://leetcode.com/problems/longest-consecutive-sequence/description/"
---

# Brute force
O(n log n)
Sort and take the longest subarray

# Optimized
O(n)
inserting into unordered_set takes O(1) time.

```cpp
int longestConsecutive(vector<int>& nums) {
	unordered_set<int> set(nums.begin(), nums.end());

	int len = 0;
	for(auto num : set){
		if(!set.count(num-1)){
			int temp = 1;
			while(set.count(num+1)){
				temp +=1;
				num++;
			}
			len = max(len, temp);
		}
	}

	return len;
}
```
