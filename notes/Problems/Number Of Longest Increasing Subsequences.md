---
link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "track len[i] and cnt[i], equal length adds counts, longer resets"
time: "O(n²)"
space: "O(n)"
date: 2023-08-10
---

# Problem
Number of longest strictly increasing subsequences.

# Approach
## LIS with Counts
[[Longest Increasing Subsequence]] plus `counter[i]`. Longer found: reset count. Same length: add counts.

### Code
```cpp
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> t(n, 0);
    vector<int> len(n, 0);
    vector<int> counter(n, 0);
    int max_length = 0, ans = 0;

    for(int i = n-1; i>=0; i--){
        int length = 1, count = 1;
        for(int j = i+1; j < n; j++){
            if(nums[j] > nums[i]){
                if(len[j] + 1 > length){
                    length = len[j] + 1;
                    count = counter[j];
                }
                else if(len[j] + 1 == length){
                    count += counter[j];
                }
            }
        }
        len[i] = length;
        counter[i] = count;

        if(length > max_length){
            ans = count;
            max_length = length;
        }
        else if(length == max_length){
            ans += count;
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$
