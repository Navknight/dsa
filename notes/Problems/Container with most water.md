---
link: https://leetcode.com/problems/container-with-most-water/
difficulty: Medium
topics:
  - "[[Two Pointers]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "two pointers from ends, move the shorter wall"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Pick two lines that hold the most water.

# Approach
## Two Pointers
`area = min height * width`. Width only shrinks, so move the shorter wall, it's the only way the min height can go up.

### Code
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int water = 0;
    while(left < right){
        int ar = min(height[right], height[left]) * (right - left);
        water = max(ar, water);
        if(height[left] < height[right])
            left++;
        else right--;
    }
    return water;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$
