---
difficulty: Medium
topics: ["Dynamic Programming", "Recursion", "Greedy", "Binary Search"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/longest-increasing-subsequence/?envType=study-plan-v2&envId=dynamic-programming"
---

[[Dynamic Programming]] [[Recursion]] [[Greedy]] [[Binary Search]]

# Problem
Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

# Solution
The recursive solution is very straight forward, we just need to start from the last element and check if the subsequent elements be taken in to the subsequence, they can be taken if they are smaller than the last taken element.

`The time complexity will be of the order 2^n` 
```cpp
int help(vector<int> &nums, int n, int maxi)
{
    if (n == 0)
        return 0;
    else
    {
        if (nums[n - 1] < maxi)
            return max(help(nums, n - 1, nums[n - 1]) + 1, help(nums, n - 1, maxi));
        else
            return help(nums, n - 1, maxi);
    }
}

int lengthOfLIS(vector<int> &nums)
{
    // return 0;
    return help(nums, nums.size(), INT32_MAX);
}
```

DP-Table
For DP, we just iterate from the last element, and for every element check every next element if they are larger or not and then add 1 to the subsequence containing them

```cpp
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int maxi = INT32_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (nums[i] < nums[j])
                temp = max(temp, ans[j] + 1);
        }
        ans[i] = temp;
        maxi = max(temp, maxi);
    }

    return maxi;
}
```


We use binary search to find the element in the ans table which is the minimum element greater than or equal to the current element and replace it with the current element

```cpp
int lengthOfLIS(vector<int> &nums)
{
	int n = nums.size();
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		if(ans.size() == 0 || ans[ans.size() - 1] < nums[i])
			ans.push_back(nums[i]);
		else
		{
			auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
			*it = nums[i];
		}
	}
	return t.size();
}
```

