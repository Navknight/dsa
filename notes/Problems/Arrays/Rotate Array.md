---
difficulty: Easy
topics: ["Arrays"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/rotate-array/description/"
code: ../../../LeetCode/rotate_array.cpp
---

[[Arrays]]

# Brute Force
Shift the elements one at a time

```cpp
void rotate(vector<int>& nums, int k) {
	while(k--){
		int temp = nums[0];
		for(int i = 0; i < nums.size(); i++){
			int ind = (i+1)%nums.size();
			swap(temp, nums[ind]);
		}
	}
}
```

# Reversing
1. Reverse the string
2. Reverse first `k` elements
3. Reverse `n-k` elements

```cpp
void reverse(vector<int>& nums, int left, int right){
	int mid = left + (right - left)/2;

	for(int i = left; i <= mid; i++){
		swap(nums[i], nums[right-i + left]);
	}
}

void rotate(vector<int>& nums, int k) {
	k %= nums.size();
	if(k == 0) return;
	reverse(nums, 0, nums.size()-1);
	reverse(nums, 0, k-1);
	reverse(nums, k, nums.size()-1);
}
```

# Cyclic Dependency
Place each element to its right position, keeping track of the replaced element. This will form a cyclic graph where replacing one element, then keeping the replaced element to the correct position. 
```cpp
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	vector<bool> visited(n, 0);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			int temp = nums[i];
			int ind = (i+k)%n;
			while(!visited[ind]){
				swap(temp, nums[ind]);
				visited[ind] = true;
				ind = (ind+k)%n;
			}
		}
	}
}
```