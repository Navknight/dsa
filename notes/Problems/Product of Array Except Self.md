---
link: https://leetcode.com/problems/product-of-array-except-self/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Prefix Sum]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "prefix products left to right into ans, then multiply by a running suffix right to left"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
`ans[i]` = product of all other elements, no division.

# Approach
## Prefix and Suffix Arrays

### Code
```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix(nums.size(), 1);
    vector<int> suffix(nums.size(), 1);

    for(int i = 1; i < nums.size(); i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    for(int i = nums.size() - 2; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    vector<int> ans(nums.size());
    for(int i = 0; i < nums.size(); i++)
        ans[i] = suffix[i] * prefix[i];

    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## In Place
Prefix pass into `ans`, then a running suffix product from the right.

### Code
```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        ans[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$ extra
