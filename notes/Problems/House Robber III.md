---
link: https://leetcode.com/problems/house-robber-iii/
difficulty: Medium
topics:
  - "[[Recursion]]"
  - "[[Trees]]"
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "each node returns {rob it, skip it}. rob = val + both skips, skip = best of each child"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
House Robber on a binary tree, no two directly linked houses.

# Approach
## Tree DP
Like [[House Robber]]. Each node returns `{rob, skip}`: rob = `val + left.skip + right.skip`, skip = `max(left) + max(right)`.

### Code
```cpp
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(0), left(nullptr), right(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> gen(Node* root, map<Node*, pair<int, int>> &t){
        if(!root)
            return t[root] = make_pair(0,0);
        else{
            if(t.find(root) != t.end())
                return t[root];

            pair<int, int> left = gen(root->left, t);
            pair<int, int> right = gen(root->right, t);

            pair<int, int> temp;

            temp.first = root->val + left.second + right.second;
            temp.second = max(left.first, left.second) + max(right.second, right.first);

            return t[root] = temp;
        }
    }

    int rob(Node* root) {
        map<Node*, pair<int, int>> t;
        pair<int, int> ans = gen(root, t);

        return max(ans.first, ans.second);
    }
};
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$
