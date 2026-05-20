---
difficulty: Medium
topics: ["Sliding Window"]
source: Leetcode
star: false
code: ../../../LeetCode/subarray_product_less_than_k.cpp
---

[[Sliding Window]]

[Subarray Product Less Than K]([Subarray Product Less Than K - LeetCode](https://leetcode.com/problems/subarray-product-less-than-k/?envType=study-plan&id=programming-skills-ii)) - Create a sliding window for the subarrays and check the multiplication, then if the multiplication is greater, move the left pointer. We calculate the number of subarrays as -> ans += right - left + 1. This is basically the breakdown of $n(n+1)/2$ which is the formula to get all subarrays.