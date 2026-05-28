---
difficulty: Medium
topics:
  - Stack
source: Leetcode
star: false
link: https://leetcode.com/problems/daily-temperatures/
date: 2026-05-28
---
[[Stack]]
# Problem
find the next greater element in an array
# Approach
check if current element is greater than the top, mark the tops next element as the current element and pop until we find the element which isnt smaller than current. Push the current element
# Code
```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> ans(n, 0);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int curr = temperatures[i];
		while (!s.empty() && temperatures[s.top()] < curr) {
			ans[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}

	return ans;
}
```
# Complexity
- Time: $O(n)$
- Space: $O(n)$
