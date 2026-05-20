---
difficulty: Medium
topics: ["Recursion", "Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/unique-binary-search-trees-ii"
---

[[Recursion]] [[Dynamic Programming]]

# Problem
Given an integer `n`, our task is to return all unique BSTs (binary search trees) that have exactly `n` nodes of unique values from `1` to `n`.

# Solution
# approach. 
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

Simple permutation approach, where we assign each element as the root and then the elements to the left of it form the left subtree. In the left subtree, all the elements to the left of original node get to be the root of the left subtree which makes the left subtree a subproblem of the original problem. We cache all the results - the start and end point and the possibilities that it generates into a map.


DP-Table approach

This is a very good approach.
So we declare a 3D array t to store all the answers the first level denotes the starting node, the next level denotes the ending node and the third level houses the answers.
so we only ever call t\[i]\[j] and it returns the whole vector at the third level.

So, when start and end nodes are equal, the answer will always be a tree with only one element that is the base case.

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