#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum(TreeNode *root, int &c)
{
    if (root == NULL)
        return 0;
    int left = max(sum(root->left, c), 0);
    int right = max(sum(root->right, c), 0);
    c = max(left + right + root->val, c);
    return max(left, right) + root->val;
}
int maxPathSum(TreeNode *root)
{
    int c = INT_MIN;
    sum(root, c);
    return c;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << maxPathSum(root) << endl;
}