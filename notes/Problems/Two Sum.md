---
link: https://leetcode.com/problems/two-sum/
difficulty: Easy
topics:
  - "[[Arrays]]"
  - "[[Hash Maps]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "map value -> index, check target - x before inserting x"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Indices of two numbers summing to `target`.

# Approach
## Hash Map
For each `x`, check if `target - x` was seen, then store `x`.

### Code
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(map.find(target - nums[i]) != map.end())
            return {map[target - nums[i]],i};
        map[nums[i]] = i;
    }
    return {};
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
