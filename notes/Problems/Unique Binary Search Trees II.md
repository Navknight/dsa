---
link: https://leetcode.com/problems/unique-binary-search-trees-ii/
difficulty: Medium
topics:
  - "[[Recursion]]"
  - "[[Dynamic Programming]]"
source: Leetcode
star: true
blind75: false
mastery:
review:
insight: "each i as root, combine every left tree from [l, i-1] with every right from [i+1, r]"
time: "O(4^n / √n)"
space: "O(4^n / √n)"
date: 
---

# Problem
All structurally unique BSTs with values `1..n`.

# Approach
## Memoized Recursion
Each `i` is the root. Combine every left tree from `[l, i-1]` with every right tree from `[i+1, r]`. Cache by `(l, r)`.

### Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleBST(int start, int end, map<pair<int, int>, vector<TreeNode*>> &t){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(nullptr);
            return res;
        }
        if(t.find(make_pair(start,end)) != t.end()){
            return t[make_pair(start, end)];
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftSubtrees = allPossibleBST(start, i-1, t);
            vector<TreeNode*> rightSubtrees = allPossibleBST(i+1, end, t);
            for(auto left: leftSubtrees){
                for(auto right: rightSubtrees){
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }

        return t[make_pair(start, end)] = res;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> t;
        return allPossibleBST(1,n,t);
    }
};
```

### Complexity
- Time: $O(4^n / \sqrt{n})$, Catalan
- Space: $O(4^n / \sqrt{n})$

## Tabulation
`t[i][j]` = all trees on `i..j`. `i == j` is a single node.

### Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> t(n+1, vector(n+1, vector<TreeNode*>(0)));
        for(int i = 1; i <= n; i++){
            t[i][i].push_back(new TreeNode(i));
        }
        for(int numNodes = 2; numNodes <= n; numNodes++){
            for(int start = 1; start <= n - numNodes + 1; start++){
                int end = numNodes + start - 1;
                for(int i = start; i<= end; i++){
                    vector<TreeNode*> leftTree = (i-1 >= start)?t[start][i-1]:vector<TreeNode*> ({NULL});
                    vector<TreeNode*> rightTree = (i+1<=end)? t[i+1][end]:vector<TreeNode*> ({NULL});

                    for(auto left : leftTree){
                        for(auto right: rightTree){
                            t[start][end].push_back(new TreeNode(i, left, right));
                        }
                    }
                }
            }
        }

        return t[1][n];
    }
};
```

### Complexity
- Time: $O(4^n / \sqrt{n})$
- Space: $O(4^n / \sqrt{n})$
