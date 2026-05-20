---
difficulty: Easy
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&id=dynamic-programming"
code: ../../../LeetCode/Climbing Stairs.cpp
---

[[Dynamic Programming]]

 Use a hash map to keep track of the values that have already been calculated, like we dont need to calculate the answer if n = 1, n = 2. So we store these in the hash map and use them when n is equal to these values. If n is equal to some number which is not yet in the map we calculate it and store it in the map for future reference. This way we dont need to calculate all the values of n <= n again and again.
eg- if n == 8, then one branch will calculate n == 7 and another will do n == 6. Now both branches will eventually need to calculate n == 5. But if n == 7 branch reaches n == 5 first, then we can just memorise the value of n == 5 and use it when n == 6 branch reaches n == 5.
