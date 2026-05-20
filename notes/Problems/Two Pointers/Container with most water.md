---
difficulty: Medium
topics: ["Two Pointers"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/container-with-most-water/description/"
---

[[Two Pointers]]

# Two Pointers
Why are we moving the pointer which points to the smaller height? 
`Area = smallerHeight * width`
so, with each movement width will surely decrease, so moving the pointer with the larger height does not make sense as if the width is decreasing we have to ensure that the min height of the columns increases.
```cpp
int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1;
	int water = 0;
	while(left < right){
		int ar = min(height[right], height[left]) * (right - left);
		water = max(ar, water);
		if(height[left] < height[right])
			left++;
		else right--;
	}
	return water;
}
```
