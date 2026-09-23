---
link: https://leetcode.com/problems/rotate-array/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "reverse all, then reverse first k and last n-k. k %= n first"
time: "O(n)"
space: "O(1)"
date: 2022-12-16
---

# Problem
Rotate an array right by `k`.

# Approach
## Brute Force
Shift by one, `k` times.

### Code
```cpp
void rotate(vector<int>& nums, int k) {
    while(k--){
        int temp = nums[0];
        for(int i = 0; i < nums.size(); i++){
            int ind = (i+1)%nums.size();
            swap(temp, nums[ind]);
        }
    }
}
```

### Complexity
- Time: $O(nk)$
- Space: $O(1)$

## Reversal
`k %= n`. Reverse all, reverse the first `k`, reverse the rest.

### Code
```cpp
void reverse(vector<int>& nums, int left, int right){
    int mid = left + (right - left)/2;

    for(int i = left; i <= mid; i++){
        swap(nums[i], nums[right-i + left]);
    }
}

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if(k == 0) return;
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, nums.size()-1);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

## Cycles
Move each element to `(i + k) % n` carrying the displaced one, following each cycle.

### Code
```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<bool> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int temp = nums[i];
            int ind = (i+k)%n;
            while(!visited[ind]){
                swap(temp, nums[ind]);
                visited[ind] = true;
                ind = (ind+k)%n;
            }
        }
    }
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
