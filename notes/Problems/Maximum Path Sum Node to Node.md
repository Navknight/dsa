---
link: https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
difficulty: Medium
topics:
  - "[[Recursion]]"
  - "[[Trees]]"
  - "[[Dynamic Programming]]"
source: GFG
star: false
blind75: false
mastery:
review:
insight: "return max(val, val + best arm), update with val + l + r"
time: "O(n)"
space: "O(h)"
date: 
---

# Problem
Max path sum between any two nodes. GFG version of [[Binary Tree Maximum Path Sum]].

# Approach
## DFS with Global Max
Return `max(val, val + max(l, r))` up. Update the answer with `max(that, val + l + r)`.

### Code
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

### Complexity
- Time: $O(n)$
- Space: $O(h)$
