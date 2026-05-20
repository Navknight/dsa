---
difficulty: Medium
topics: ["Binary Search", "DFS", "Trees", "BFS", "Linked Lists"]
source: Leetcode
star: false
code: ../../../LeetCode/Linked_list_in_binary_tree.cpp
---
[[Binary Search]] [[DFS]] [[Trees]] [[BFS]] [[Linked Lists]]

 [ List in  ]([ List in   - LeetCode](https://leetcode.com/problems/linked-list-in-binary-tree/submissions/931286310/?envType=study-plan&id=programming-skills-ii))
	1. Using  - create a dfs algorithm which checks if the current root val and head val are equal and if they are equal then continue the search for head->next, root->left and right.
	2. Using bfs - Instead of searching on one side of the tree first, we use a queue to store the nodes of the tree and compare the value of the linked list with the elements in the queue, the algorithm remains the same its just the order in which the algorithm is used on different nodes.