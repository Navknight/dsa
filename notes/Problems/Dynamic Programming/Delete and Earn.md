---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
code: LeetCode/Delete_and_earn.cpp
---
[[LeetCode/Delete_and_earn.cpp]]
[[Dynamic Programming]]

[[House Robber]] 
This problem is very similar to the house robber problem, here if the nums array is converted to a array with only unique elements, with the frequencies of those elements stored in a hash-map, we can see that if two consecutive elements in the array differ by only one, then we can only chose one of them and not both. This case makes it essentially the same as the house robber problem with an exception of the other case where consecutive elements differ by more than one in which case we can always take both of them.

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