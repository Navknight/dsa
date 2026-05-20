---
difficulty: Medium
topics: ["Arrays", "Prefix Sum"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/product-of-array-except-self/description/"
---

[[Arrays]] [[Prefix Sum]]

# Prefix and Suffix Products
O(n + n + n)

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

# Optimised
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
