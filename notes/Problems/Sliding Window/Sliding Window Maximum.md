---
difficulty: Hard
topics:
  - Sliding Window
  - Two Pointers
  - Hash Maps
  - Deque
source: Leetcode
star: false
link: https://leetcode.com/problems/sliding-window-maximum/description/
date: 2026-05-22
---

[[Sliding Window]], [[Two Pointers]], [[Hash Maps]], [[Deque]]

# Problem

Return the array of maximums in a sliding window

# Approach
## Two Pointers

Keep a frequency map of all the elements in the window, if the frequency of the maximum goes to 0, scan the window for a new maximum.

### Code

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	unordered_map<int, int> mp;

	int l = 0, r = 0, maxr = INT_MIN, n = nums.size();
	while (r < n) {
		mp[nums[r]]++;
		maxr = max(maxr, nums[r]);
		if (r - l + 1 == k) {
			ans.push_back(maxr);
		} else if (r - l + 1 > k) {
			mp[nums[l++]]--;
			if (mp[maxr] == 0) {
				maxr = INT_MIN;
				for (int i = l; i <= r; i++) {
					maxr = max(maxr, nums[i]);
				}
			}
			ans.push_back(maxr);
		}
		r++;
	}
	return ans;
}
```

### Complexity
- Time: $O(n*k)$
- Space: $O(k)$
## Deque
Maintain a deque, where the front element denotes the largest element still in the window.
SO, on a new element, we throw away all the elements in the window that are smaller than it, because the new element is larger than them and will leave the window later than them.
The front element is thrown away if it is outside the window

### Code
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	deque<int> dq;

	int n = nums.size();

	for (int r = 0; r < n; r++) {
		if (!dq.empty() && dq.front() < r - k + 1) {
			dq.pop_front();
		}

		while (!dq.empty() && nums[dq.back()] < nums[r]) {
			dq.pop_back();
		}

		dq.push_back(r);

		if (r >= k - 1) {
			ans.push_back(nums[dq.front()]);
		}
	}

	return ans;
}
```
### Complexity
- Time: $O(n)$
- Space: $O(n)$