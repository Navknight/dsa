---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
code: LeetCode/House_robber.cpp
---
[[LeetCode/House_robber.cpp]]
[[Dynamic Programming]]

[House Robber - LeetCode](https://leetcode.com/problems/house-robber/?envType=study-plan-v2&id=dynamic-programming) This Problem is like [[01 KnapSack]].  
**Recursive Approach with Memorization:**

The `helper` function uses a recursive approach to solve the problem, where it calculates the maximum amount that can be robbed starting from a given index in the `nums` array. It uses memoization to avoid redundant calculations.

The `helper` function takes three parameters: `nums` (the array of house values), `index` (the current index being considered), and `memo` (an array to store the calculated results for each index). 

At each index, the function checks if the result for that index has already been calculated and stored in the `memo` array. If so, it returns the stored result. Otherwise, it calculates the maximum amount that can be robbed either by robbing the current house and moving two steps ahead (`nums[index] + helper(nums, index + 2, memo)`), or by skipping the current house and moving one step ahead (`helper(nums, index + 1, memo)`). It then stores the maximum amount in the `memo` array for future reference and returns it.

The `rob` function initializes the `memo` array with `-1` values and calls the `helper` function with the initial parameters `nums` and `index=0`. It returns the maximum amount that can be robbed by calling the `helper` function.

**Recursive Approach with Better Space Complexity:**

The `helper` function uses a recursive approach to solve the problem, similar to the previous approach, but with better space complexity. It avoids creating new subarrays and instead uses indices (`start` and `end`) to represent the range of houses being considered.

The `helper` function takes four parameters: `nums` (the array of house values), `start` (the starting index of the current range), `end` (the ending index of the current range), and `sum` (the sum of values of previously robbed houses).

At each step, the function checks the base cases: if `start >= end`, it means there are no more houses to consider, so it returns 0. If there is only one house in the range (`end - start == 1`), it returns the sum of the house value and the `sum` parameter.

Otherwise, it recursively calculates the maximum amount that can be robbed either by robbing the current house and moving two steps ahead (`nums[start] + helper(nums, start + 2, end, sum)`),

```cpp
int helper(vector<int> &nums, int index, vector<int> &memo)
// Memorisation
{

    if (index >= nums.size())

        return 0;

    if (memo[index] != -1)

        return memo[index];

    int robCurrent = nums[index] + helper(nums, index + 2, memo);

    int skipCurrent = helper(nums, index + 1, memo);

    int maxAmount = max(robCurrent, skipCurrent);

    memo[index] = maxAmount;

    return maxAmount;
}

int helper(vector<int> &nums, int start, int end, int sum)
// Recursion but with better space complexity
{

    if (start >= end)

        return 0;

    else if (end - start == 1)

        return sum + nums[start];

    else

        return max(sum + nums[start] + helper(nums, start + 2, end, sum), sum + helper(nums, start + 1, end, sum));
}

int robber(vector<int> &nums, int sum)
// Recursion with worse space complexity
{

    if (nums.size() == 0)
        return 0;

    else if (nums.size() == 1)

        return sum + nums[0];

    else
    {

        vector<int> nums1(nums.begin() + 1, nums.end());

        vector<int> nums2(nums.begin() + 2, nums.end());

        return max(sum + nums[0] + robber(nums2, sum), sum + robber(nums1, sum));
    }
}

int robber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    else if (n == 1)
        return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int rob(vector<int> &nums)

{

    int n = nums.size();

    vector<int> memo(n, -1);

    return helper(nums, 0, memo);
}
```
