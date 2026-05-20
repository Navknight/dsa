---
difficulty: Medium
topics: ["Linked Lists"]
source: Leetcode
star: false
code: ../../../LeetCode/copy_list_with_random_pointer.cpp
---

[[Linked Lists]]

[Copy List With Random Pointer]((https://leetcode.com/problems/copy-list-with-random-pointer/submissions/931454159/?envType=study-plan&id=programming-skills-ii))  Maintain a hashmap from <Node*,Node*>. It will have the given list nodes as key and the copied list nodes as values so that we can find out if a given random node was already created or not. Rest is just a traversal and new node creation.