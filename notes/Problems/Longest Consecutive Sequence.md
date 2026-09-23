---
link: https://leetcode.com/problems/longest-consecutive-sequence/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "hash set, only start counting from x where x - 1 isn't in the set"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Longest run of consecutive values, unsorted input, O(n).

# Approach
## Sort
Sort and find the longest run. $O(n \log n)$.

## Hash Set
Only start counting at a sequence start (`x - 1` not in the set), so each value is walked once.

### Code
```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());

    int len = 0;
    for(auto num : set){
        if(!set.count(num-1)){
            int temp = 1;
            while(set.count(num+1)){
                temp +=1;
                num++;
            }
            len = max(len, temp);
        }
    }

    return len;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
