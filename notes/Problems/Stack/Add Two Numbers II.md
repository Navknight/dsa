---
difficulty: Medium
topics: ["Stack", "Linked Lists"]
source: Leetcode
star: false
code: ../../../LeetCode/add_two_numbers_II.cpp
---

[[Stack]] [[Linked Lists]]

[Add Two Numbers II - LeetCode](https://leetcode.com/problems/add-two-numbers-ii/?envType=study-plan-v2&id=programming-skills)as the most significant digit is the first one, we need to add the linked lists in reverse order. The best way is to use stacks to store the lists as we traverse them and then use the stacks to add them and store them into a third linked list as the stack will automatically pop the items in the reverse order.