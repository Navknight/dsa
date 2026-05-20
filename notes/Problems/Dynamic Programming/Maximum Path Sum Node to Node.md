---
difficulty: Medium
topics: ["Recursion", "Trees", "Dynamic Programming"]
source: GFG
star: false
link: "https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article"
---

[[Recursion]] [[Trees]] [[Dynamic Programming]]

# Problem
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

# Solution
Since we don't always need to go to the leaf, there can be a node which has a higher value than the left and right subtree maximum path sums

```cpp
int solve(Node* root, int &sum){
    if(root == NULL)
        return 0;
    int left = solve(root->left, sum);
    int right = solve(root->right, sum);
    
    int temp = max(max(left, right) + root->data, root->data);
    int ans = max(temp, root->data + left + right);
    sum = max(sum, ans);
    return temp;
}

int findMaxSum(Node* root)
{
    // Your code goes here
    int sum = INT32_MIN;
    int temp = solve(root, sum);
    return sum;
}
```

