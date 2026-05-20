---
difficulty: Medium
topics: ["Recursion", "Trees", "Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/house-robber-iii"
---

[[Recursion]] [[Trees]] [[Dynamic Programming]]

# Problem
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return _the maximum amount of money the thief can rob **without alerting the police**_.

# Solution
This problem is similar to the [[House Robber]] problem, the only difference being the data structure used to represent the houses. So we use the same approach here, but instead of having an iterative DP, we have recursion + memorisation.

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