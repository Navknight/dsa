---
link: https://leetcode.com/problems/next-greater-element-ii/
difficulty: Medium
topics:
  - "[[Stack]]"
  - "[[Monotonic Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "loop 2n with i % n, monotonic stack of indices"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Next greater element in a circular array.

# Approach
## Monotonic Stack
Loop `2n - 1` times with `i % n` to simulate the wrap. Pop smaller values off the stack and set their answer.

### Code
```cpp
vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> s;

    for(int i = 0; i < 2*nums.size()-1; i++){
        int j = i%nums.size();
        while(!s.empty() && nums[s.top()] < nums[j]){
            ans[s.top()] = nums[j];
            s.pop();
        }
        s.push(j);
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
