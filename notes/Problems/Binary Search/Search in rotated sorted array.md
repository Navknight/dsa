---
difficulty: Medium
topics: ["Binary Search"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/search-in-rotated-sorted-array/"
---

[[Binary Search]]

At a given time, two of `l`, `m` and `r` belong to the same side of the inflection point. Inflection point in - [[Find Minimum in Rotated Sorted Array]]

So, when we find the inflection point, we can just eliminate one half of the array.
```cpp
int search(vector<int>& nums, int target) {
	int l = 0, r = nums.size()-1, ans = -1;

	if(nums.size() == 1)
		return (nums[0] == target) ? 0 : -1;

	while(l <= r) {
		int m = l + (r-l)/2;
		if(nums[m] == target) 
			return m;
		if(nums[l] <= nums[m]) {
			if(target < nums[l] || target > nums[m]){
				l = m+1;
			}
			else {
				r = m-1;
			}
		} else {
			if (target > nums[r] || target < nums[m])
				r = m-1;
			else 
				l = m + 1;
		}
	}

	return ans;
}
```
