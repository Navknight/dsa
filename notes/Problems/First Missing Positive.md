---
link: https://leetcode.com/problems/first-missing-positive/
difficulty: Hard
topics:
  - "[[Arrays]]"
  - "[[Hash Maps]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "cyclic sort: swap each value v in 1..n to index v-1, first i with nums[i] != i+1 is the answer"
time: "O(n)"
space: "O(1)"
date: 2022-12-15
---

# Problem
Smallest missing positive integer, O(n) time, O(1) space.

# Approach
## Cyclic Sort
The answer is in `1..n+1`. Swap each in-range value to its home index `v - 1` until it's there or a duplicate sits there. First index with the wrong value is the answer, else `n + 1`.

### Code
```cpp
int firstMissingPositive(vector<int> &nums)
{
    for (int i = 0; i < nums.size();)
    {
        if (nums[i] >= 1 && nums[i] <= nums.size())
        {
            int cor_pos = nums[i] - 1;
            if (nums[i] != nums[cor_pos])
            {
                swap(nums[i], nums[cor_pos]);
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return nums.size() + 1;
}
```

### Complexity
- Time: $O(n)$, each swap places one value for good
- Space: $O(1)$
