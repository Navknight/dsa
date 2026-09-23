---
link: https://leetcode.com/problems/3sum/
difficulty: Medium
topics:
  - "[[Hash Maps]]"
  - "[[Two Pointers]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "sort, fix i, two pointers on the rest. skip equal neighbours to dedup"
time: "O(n²)"
space: "O(1)"
date: 
---

# Problem
Find all unique triplets that sum to 0.

# Approach
## Hash Map
Reduce to [[Two Sum]] for every pair (i, j). Decrement counts so used elements aren't reused.

### Code
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> map;
    for(auto num: nums)
        map[num]++;


    vector<vector<int>> ans;

    for(int i = 0; i < nums.size(); i++){
        map[nums[i]]--;
        if(i > 0 && nums[i-1] == nums[i]) continue;
        for(int j = i+1; j < nums.size(); j++){
            map[nums[j]]--;
            if(j > i+1 && nums[j-1] == nums[j]) continue;

            int target = -(nums[i] + nums[j]);
            if(map[target] > 0){
                ans.push_back({target, nums[i], nums[j]});
            }
        }

        for(int j = i+1; j < nums.size(); j++){
            map[nums[j]]++;
        }
    }
    return ans;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n)$

## Two Pointers
Sort. Fix `nums[i]`, find pairs summing to `-nums[i]` with two pointers. Skip duplicates for `i` and after each match.

### Code
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i-1] == nums[i])
            continue;

        int left = i+1, right = nums.size()-1;
        int target = -nums[i];
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                ans.push_back({nums[left], nums[right], nums[i]});
                left++;
                right--;

                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            } else if(sum > target) right--;
            else left++;
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n^2)$
- Space: $O(1)$
