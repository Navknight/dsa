---
difficulty: Medium
topics: ["Binary Search"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/"
---

[[Binary Search]]

Inflection Point - point where the array has a dip - \[4, 5, 6, 1, 2, 3], here 1 is the inflection point as the array is increasing before and after 1.

As the list is sorted in ascending order, anytime left pointer is smaller than right pointer, we will be at the inflection point.

```cpp
int findMin(vector<int>& nums) {
	int l = 0, r = nums.size() - 1, ans = nums[0];

	while(l <= r) {
		if(nums[l] < nums[r])
			ans = min(ans, nums[l]);
		
		int m = l + (r-l)/2;
		ans = min(ans, nums[m]);

		if(nums[m] >= nums[l])
			l = m + 1;
		else 
			r = m - 1;
	}

	return ans;
}
```

