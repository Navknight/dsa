---
difficulty: Medium
topics:
  - Stack
source: Leetcode
star: false
link: https://leetcode.com/problems/car-fleet/
date: 2026-05-30
---
# Problem
Cars of different speed travel to target, we need to find how many cars will reach the target together if overtaking isnt allowed. So the number of groups of cars moving at the same speed to the target
# Approach
1. Sort in ascending order, so now if a slower car is ahead we can detect
2. Use stack to track slower cars. If there is a slower car ahead then all the cars behind it will form a fleet with it
3. Pop until we find a slower car group compared to the currentcar
# Code
```cpp
int carFleet(int target, vector<int>& position, vector<int>& speed) {
	vector<pair<int, int>> cars;
	int n = position.size();
	for (int i = 0; i < n; i++) {
		cars.push_back({position[i], speed[i]});
	}

	sort(cars.begin(), cars.end());

	stack<pair<int, int>> s;

	for (const auto& i : cars) {
		double time = (double)(target - i.first) / (double)i.second;
		while (!s.empty()) {
			const auto& j = s.top();
			double t = (double)(target - j.first) / (double)j.second;
			if (t <= time)
				s.pop();
			else
				break;
		}
		s.push(i);
	}

	return s.size();
}
```
# Complexity
- Time: $O(nlogn)$ `Sorting`
- Space:$O(n)$
