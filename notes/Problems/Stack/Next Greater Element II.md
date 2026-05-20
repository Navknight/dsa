---
difficulty: Medium
topics: ["Stack", "Monotonic Stack"]
source: Leetcode
star: false
---

[[Stack]] [[Monotonic Stack]]

[Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/?envType=study-plan&id=programming-skills-ii)   
	1. Trivial Solution - Use two nested fro loops to loop over the array in a cicular fashion and fin the next greatest element for each element.
	2. Optimised - Use one for loop that loops over the nums array twice (joining two nums arrays together, imaginary) and then use the stack to find the next greater element.