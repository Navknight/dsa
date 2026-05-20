---
difficulty: Medium
topics: ["Greedy"]
source: Leetcode
star: false
---

[[Greedy]]

[Smallest Range II]([Smallest Range II - LeetCode](https://leetcode.com/problems/smallest-range-ii/description/?envType=study-plan&id=programming-skills-ii))   # # - Sort the array. Now since the array is sorted the candidates for max will be - (a[n-1] - k) or a[i] + k and for min it will be a[0] + k or a[i+1] -k. we can use these 4 variables to arrive at the answer.  