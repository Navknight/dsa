---
difficulty: Easy
topics: ["Arrays"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/"
---

[[Arrays]]

# Brute Force

```cpp
bool check(vector<int>& nums) {
	if(nums.size() <= 1)
		return true;
	bool ans = false;

	for(int i = 0; i < nums.size() && !ans; i++){
		for(int j = 0; j < nums.size()-1; j++){
			if(nums[(j+i)%nums.size()] <= nums[(j+1+i)%nums.size()]){
				ans = true;
			} else {
				ans = false;
				break;
			}
		}
	}

	return ans;
}
```

At every index check if a sorted array is possible

# Optimized
```cpp
bool check(vector<int>& nums) {
	int count = 0;

	for(int i = 0; i < nums.size()-1; i++){
		if(nums[i] > nums[i+1])
			count++;
	}

	if(nums[nums.size()-1] > nums[0])
		count++;

	return (count > 1 )? false : true;
}
```

If the array is sorted, then there can only be one point where the next element can be smaller than the current element no matter how its rotated.
