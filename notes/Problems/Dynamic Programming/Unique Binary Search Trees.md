---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/unique-binary-search-trees/description/?envType=study-plan-v2&envId=dynamic-programming"
---

[[Dynamic Programming]]

# Problem::
Given an integer `n`, return _the number of structurally unique **BST'**s (binary search trees) which has exactly_ `n` _nodes of unique values from_ `1` _to_ `n`.

# Solution
This problem has the [[Catalan's Number]] as it's solution. for each number in 1-n, we have a choice, either it will be the node or not, then if its a node all the numbers to its left will be in the left subtree and they will have a choice to be the root of that subtree, same for the right subtree.

This adds up to the catalan's number

```cpp
int numTrees(int n) {
    vector<int>t (n+1, 1);

    for(int i = 2; i < n+1; i++){
        int total = 0;
        for(int j = 1; j <= i; j++){
            total += t[j-1]*t[i-j];
        }
        t[i] = total;
    }

    return t[n];
}
```
