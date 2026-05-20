---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/?envType=study-plan-v2&envId=dynamic-programming"
code: ../../../LeetCode/number_of_longest_increasing_subsequences.cpp
---

[[Dynamic Programming]]

# Problem
Given an integer array `nums`, return _the number of longest increasing subsequences._
**Notice** that the sequence has to be **strictly** increasing.

# Solution
This problem is an extended version of the [[Longest Increasing Subsequence]] problem. We use the same solution as in that problem but we have to count the number of ways in which the maximum occurs, so we define 2 new variables - the max_length and the ans. These keep track of the maximum length encountered so far and they also track how many times that length has appeared so far.

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