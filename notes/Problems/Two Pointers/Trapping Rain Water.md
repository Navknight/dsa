---
difficulty: Hard
topics:
  - Arrays
  - Two Pointers
source: Leetcode
star: true
link: https://leetcode.com/problems/trapping-rain-water/
date: 2026-05-19
---
[[Two Pointers]] [[Arrays]]
# Problem

Find the water trapped between the walls in an array
# Approach
## Prefix and Suffix Maximum
Calculate the prefix and suffix max at a point to know the highest walls on left and right, then take the min of the highest on left and right walls to know the amount trapped.
### Code
```cpp
int trap(vector<int>& height) {
	int n = height.size();
	vector<int> pre(n, 0), suf(n, 0);
	pre[0] = height[0];
	suf[n - 1] = height[n - 1];
	for (int i = 1; i < n; i++) {
		pre[i] = max(pre[i - 1], height[i - 1]);
	}

	for (int i = n - 2; i >= 0; i--) {
		suf[i] = max(suf[i + 1], height[i + 1]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (pre[i] != 0 && suf[i] != 0 && height[i] < min(pre[i], suf[i]))
			ans += min(pre[i], suf[i]) - height[i];
	}

	return ans;
}
```
### Complexity
- Time: $O(n)$
- Space: $O(n)$
## Two pointers
#### Naïve:
Use two pointers to point to the greatest height to the left and right of the current element. the height of the water trapped would be $min(height[l], height[r]) - height[curr]$ as the width is always 1. 
#### Code
```cpp
int trap(vector<int>& height) {
	int n = height.size();
	int l = 0, ans = 0;

	while (l < n) {
		while (l < n && height[l] == 0)
			l++;
		if (l >= n)
			break;

		int r = l + 1;
		int maxr = 0, pr = l;

		while (r < n) {
			if (height[r] >= maxr) {
				maxr = height[r];
				pr = r;
			}
			if (height[r] < height[l])
				r++;
			else
				break;
		}

		for (int p = l + 1; p < pr; p++)
			ans += min(height[l], maxr) - height[p];

		// if scan exhausted and found something beyond l, continue from pr
		if (pr > l && pr != r)
			l = pr;
		else
			l = r;
	}

	return ans;
}
```
#### Complexity
- Time: $O(n^2)$
- Space: $O(1)$
#### Optimised: 
So always, one side is the limiting factor. We can take the side which is smaller, compute the water for that side and move it inwards.
#### Code
```cpp
int trap(vector<int>& height) {
	int n = height.size();
	int l = 0, r = n - 1, ans = 0;
	int leftMax = height[l], rightMax = height[r];
	while (l < r) {
		leftMax = max(leftMax, height[l]);
		rightMax = max(rightMax, height[r]);
		if (leftMax < rightMax) {
			ans += leftMax - height[l++];
		} else {
			ans += rightMax - height[r--];
		}
	}

	return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$