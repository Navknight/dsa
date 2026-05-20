---
difficulty: Medium
topics: ["Sliding Window"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/frequency-of-the-most-frequent-element"
---

[[Sliding Window]]

```cpp
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long sum = 0;
    int left = 0;
    int result = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        while ((long long)nums[right] * (right - left + 1) - sum > k) {
            sum -= nums[left];
            ++left;
        }

        result = max(result, right - left + 1);
    }

    return result;
}
```

