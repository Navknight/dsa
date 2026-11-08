---
link: https://leetcode.com/problems/time-based-key-value-store/
difficulty: Medium
topics:
  - "[[Hash Maps]]"
  - "[[Binary Search]]"
source: Leetcode
star: false
blind75: false
mastery: green
review: 2026-11-15
insight: "map key -> vector of (timestamp, value), timestamps arrive increasing so push_back keeps it sorted, get binary searches the last timestamp <= t"
time: "O(1) set, O(log n) get"
space: "O(n)"
date: 2026-11-08
---

# Problem
`set(key, value, timestamp)` and `get(key, timestamp)` returning the value with the largest stored timestamp <= the query, or `""`.

# Approach
## Map of sorted histories + binary search
Timestamps for a key only increase, so each history is already sorted. `get` is a "last index where timestamp <= t" search.

- `map[key]` in `get` inserts an empty entry for a missing key. Use `find`
- Save the best index and copy the string once at the end
- Pass `key` and `value` by `const string&`
- Can't beat O(log n) for `get`, it is a predecessor search

### Code
```cpp
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> map;

public:
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto& values = map[key];
        int l = 0, r = values.size() - 1;
        string result = "";
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (values[m].first <= timestamp) {
                result = values[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }
};
```

### Complexity
- Time: $O(1)$ for `set`, $O(\log n)$ for `get`
- Space: $O(n)$
