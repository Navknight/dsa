---
difficulty: Easy
topics: ["Arrays"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/"
---

[[Arrays]]

```cpp
int removeDuplicates(vector<int>& nums) {
	if(nums.size() <= 1)
		return nums.size();
	int ptr = 1;
	int k = 1;
	for(int i = 0; i < nums.size()-1; i++){
		if(nums[i] != nums[i+1]){
			k++;
			nums[ptr++] = nums[i+1];
		}
	}

	return k;
}
```

- There will always be 1 unique element in an array at - least.
- We dont need to save anything, we can overwrite the duplicate elements with the unique ones as teh judge does not care what comes after the unique elements in the returned array.

Q. If we were required to swap instead of in-place overwrite?
=> We can use the snowball technique.
