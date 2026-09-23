---
link: https://leetcode.com/problems/delete-and-earn/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sum value * freq per unique value, then house robber where adjacent values conflict"
time: "O(n log n)"
space: "O(n)"
date: 2023-05-23
---

# Problem
Take `nums[i]` to earn it and delete all `nums[i] ± 1`. Max points.

# Approach
## House Robber on Unique Values
Sort, collect unique values and their counts. Consecutive values (diff 1) can't both be taken, that's [[House Robber]]. Diff > 1 means take both.

### Code
```cpp
int deleteAndEarn(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    unordered_map<int, int> m;
    vector<int> uni;
    int prev = -1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
        if (nums[i] == prev)
            continue;
        else
        {
            uni.push_back(nums[i]);
            prev = nums[i];
        }
    }

    int t1 = 0, t2 = 0;

    for (int i = 0; i < uni.size(); i++)
    {
        if (i > 0 && uni[i] - uni[i - 1] == 1)
        {
            int temp = t2;
            t2 = max(t2, t1 + uni[i] * m[uni[i]]);
            t1 = temp;
        }
        else
        {
            int temp = t2;
            t2 = t2 + uni[i] * m[uni[i]];
            t1 = max(temp, t1);
        }
    }

    return max(t1, t2);
}
```

### Complexity
- Time: $O(n \log n)$
- Space: $O(n)$
