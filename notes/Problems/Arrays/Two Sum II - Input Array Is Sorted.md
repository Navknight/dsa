---
difficulty: Medium
topics:
  - Arrays
  - Binary Search
  - Two Pointers
source: Leetcode
star: false
link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
date: 2026-05-18
---

[[Arrays]] [[Binary Search]] [[Two Pointers]]

# Problem

Two sum but with sorted array

# Approach
## Binary Search
We can fix a left pointer and search in the right side of the array, if the $target - numbers[l]$ is greater than $numbers[l]$ then there is no possible solution.

### Code
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
	int n = numbers.size();
	for (int l = 0; l < n - 1; l++) {
		int t = target - numbers[l];
		if (numbers[l] > t)
			break;

		int r = l + 1, e = n - 1;
		while (r <= e) {
			int m = r + (e - r) / 2;
			if (numbers[m] == t)
				return {l + 1, m + 1};
			else if (numbers[m] < t)
				r = m + 1;
			else
				e = m - 1;
		}
	}
	return {};
}
```
### Complexity
- Time: $O(nlogn)$
- Space: $O(1)$
## Two Pointers
As the array is sorted, we can start on the opposite end and make it to the middle
### Code
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
	int n = numbers.size();
	int l = 0, r = n - 1;

	while (l <= r) {
		if (numbers[l] + numbers[r] == target)
			return {l + 1, r + 1};
		else if (numbers[l] + numbers[r] > target)
			r--;
		else
			l++;
	}

	return {};
}
```
### Complexity
- Time: $O(n)$
- Space: $O(1)$