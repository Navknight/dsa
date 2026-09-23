---
link: https://leetcode.com/problems/car-fleet/
difficulty: Medium
topics:
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort by position, time to target; a car behind that arrives sooner joins the fleet ahead"
time: "O(n log n)"
space: "O(n)"
date: 2026-05-30
---

# Problem
Cars can't overtake. Count the fleets that reach the target.

# Approach
## Sort + Stack
Sort by position. Time to target = `(target - pos) / speed`. Pop cars behind that arrive no later than the current one, they merge into its fleet. Stack size = fleets.

### Code
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

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
