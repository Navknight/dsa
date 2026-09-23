---
link: https://leetcode.com/problems/arithmetic-subarrays/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "sort each queried subarray, check all adjacent differences are equal"
time: "O(m * n log n)"
space: "O(n)"
date: 2023-04-05
---

# Problem
For each range query, check if the subarray can be rearranged into an arithmetic sequence.

# Approach
## Sort Each Query
Push the range into a max heap, pop in order and check every adjacent difference is the same.

### Code
```cpp
bool check(vector<int> nums, int a, int b)
{
    priority_queue<int> pq;
    for(int i = a; i <= b; i++){
        pq.push(nums[i]);
    }
    if(pq.size() <= 1)
        return true;
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    int d = x-y;

    while(!pq.empty()){
        x = pq.top();
        pq.pop();
        if(y-x != d)
            return false;
        y = x;
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    vector<bool> ans;
    for (int i = 0; i < l.size(); i++)
    {
        int a = l[i];
        int b = r[i];
        ans.push_back(check(nums, a, b));
    }
    return ans;
}
```

### Complexity
- Time: $O(m \cdot n \log n)$
- Space: $O(n)$
